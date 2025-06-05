#include <string.h>
#include <strings.h>
#include "sway/commands.h"
#include "log.h"

struct cmd_results *bar_cmd_notch(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "notch", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	int notch_width = atoi(argv[0]);
	sway_log(SWAY_DEBUG, "Setting notch size %d", notch_width);
	config->current_bar->notch = notch_width;

	return cmd_results_new(CMD_SUCCESS, NULL);
}
