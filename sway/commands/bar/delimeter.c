#include <string.h>
#include <strings.h>
#include "sway/commands.h"
#include "log.h"

struct cmd_results *bar_cmd_delimeter(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "delimeter", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	char *delim = strdup(argv[0]);
	sway_log(SWAY_DEBUG, "Setting bar delimeter: %s", delim);
	if (config->current_bar->delimeter) {
	  free(config->current_bar->delimeter);
	}
	config->current_bar->delimeter = delim;

	return cmd_results_new(CMD_SUCCESS, NULL);
}
