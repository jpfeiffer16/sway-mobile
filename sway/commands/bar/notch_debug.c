#include <string.h>
#include <strings.h>
#include "sway/commands.h"
#include "log.h"
#include "util.h"

struct cmd_results *bar_cmd_notch_debug(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "notch_debug", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}
	sway_log(SWAY_INFO, "DEBUG: setting notch_debug, arg: %s", argv[0]);
	config->current_bar->notch_debug =
		parse_boolean(argv[0], config->current_bar->notch_debug);
	if (config->current_bar->notch_debug) {
		sway_log(SWAY_DEBUG, "Enabling notch size debugging for bar: %s",
				config->current_bar->id);
	} else {
		sway_log(SWAY_DEBUG, "Disabling notch size debugging for bar: %s",
				config->current_bar->id);
	}
	return cmd_results_new(CMD_SUCCESS, NULL);
}
