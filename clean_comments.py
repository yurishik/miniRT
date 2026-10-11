import sys
import re
from pathlib import Path

def clean_comments(file_path):
    with open(file_path, "r", encoding="utf-8") as f:
        lines = f.readlines()

    header = lines[:11]
    body = "".join(lines[11:])

    # 1. コメントのみで構成される行（単一行・複数行ブロック）を改行ごと削除
    full_line_comment_pattern = re.compile(
        r'^[ \t]*(?:/\*[\s\S]*?\*/|//[^\r\n]*)\r?\n?',
        re.MULTILINE
    )
    body = full_line_comment_pattern.sub("", body)

    # 2. コード行末のコメントを削除（文字列リテラル "..." や '...' は保護）
    inline_comment_pattern = re.compile(
        r'("(?:\\.|[^"\\])*")|'
        r"('(?:\\.|[^'\\])*')|"
        r'([ \t]*(?:/\*.*?\*/|//[^\r\n]*)$)',
        re.MULTILINE
    )

    def replace_inline(match):
        # 文字列や文字リテラルはそのまま保持
        if match.group(1):
            return match.group(1)
        if match.group(2):
            return match.group(2)
        # 行末コメント部分は空文字にして除去
        return ""

    body = inline_comment_pattern.sub(replace_inline, body)

    with open(file_path, "w", encoding="utf-8") as f:
        f.writelines(header)
        f.write(body)

    print(f"Processed: {file_path}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python clean_comments.py <file_or_directory>")
        sys.exit(1)

    target = Path(sys.argv[1])
    files = [target] if target.is_file() else list(target.rglob("*.c")) + list(target.rglob("*.h"))
    for file in files:
        clean_comments(file)
