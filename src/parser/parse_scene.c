#include "minirt.h"

int	parse_scene(t_scene *scene, const char *filename)
{
	char				**lines;
	t_element_counts	counts;

	lines = read_valid_lines(filename);
	if (!lines)
		return (print_error("Failed to read file"));
	if (validate_structure(lines, &counts) == HAS_ERROR
		|| validate_lines(lines, scene) == HAS_ERROR)
	{
		free_str_array(lines);
		return (HAS_ERROR);
	}
	free_str_array(lines);
	return (NO_ERROR);
}
