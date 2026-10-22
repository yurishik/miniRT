miniRT peer-review scene tests (Subject v10.0)

Folders:
5.5_translations_rotations: 01 sphere translation, 02/03 cylinder before/after 90-degree rotation around Z.
5.6_multi_objects: intersecting sphere/cylinder, and multiple objects of the same types.
5.7_camera_position_direction: camera positioned on X/Y/Z axes and at an arbitrary off-axis position; looking toward origin.
5.8_brightness: side lighting of sphere before/after translation.
5.9_shadows: one sphere casting a shadow on a plane, and a scene with several objects.

Usage: ./miniRT <path/to/file.rt>

Notes:
- All scenes use only A, C, L, sp, pl and cy defined by the mandatory subject.
- Rotating a cylinder 90 degrees about Z turns its axis from (0,1,0) into (+/-1,0,0); compare 02 and 03.
- In 5.5/01, the back sphere is larger, so both can be observed even though the centers line up along the camera direction; translation is 7, greater than each diameter (2 and 5).
- In 5.7/04, the direction vector is approximately normalized; minor decimal rounding is expected.
- In 5.8, compare the direction of the highlight/illumination after moving the sphere.
- A successful render alone does not establish that lighting, intersections, or shadows are correct: inspect the images.

5.5_translations_rotations: 01 球の平行移動。02/03 円柱のZ軸周り90度回転（回転前後）。
5.6_multi_objects: 球と円柱の交差、および同種オブジェクトの複数配置。
5.7_camera_position_direction: カメラをX/Y/Z軸上および軸外の任意の位置に配置し、原点方向を向かせたシーン。
5.8_brightness: 球の平行移動前後における、側面からの照明効果。
5.9_shadows: 平面上に球が影を落とすシーン、および複数のオブジェクトを配置したシーン。

使用方法: ./miniRT <path/to/file.rt>

注意事項:
- すべてのシーンにおいて、課題仕様で必須とされている要素（A, C, L, sp, pl, cy）のみを使用しています。
- 円柱をZ軸周りに90度回転させると、その軸ベクトルは (0,1,0) から (+/-1,0,0) に変化します（02と03を比較してください）。
- 5.5/01では、奥にある球の方が大きいため、中心がカメラ方向の直線上に並んでいても両方の球が視認できます。平行移動距離は7であり、各球の直径（2および5）よりも大きくなっています。
- 5.7/04において、方向ベクトルは概ね正規化されていますが、計算過程でわずかな端数処理（丸め）が生じる可能性があります。
- 5.8では、球を移動させた後のハイライトや照明の向きの変化を確認してください。
- レンダリングが正常に完了したからといって、照明、交差判定、影の処理がすべて正しいとは限りません。必ず生成された画像を目視で確認してください。