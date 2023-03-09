/* me.c:    IRC /me for your command-line if you are lonely and
 *          or interested in expressing your emotions to a lifeless
 *          machine.
 *
 * License: MIT
 * NOTE:    If you want to use it without a dot-slash prefix it needs to be
 *     	    in your root directory (/). It is a safe program, but do so
 *          at your own risk.
 * Written: Joey DeFrancesco
 * Year:    2005
 * Usage:   /me YOUR_TEXT
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool print_username()
{
	/* Get username. */
	const char *user_name = getenv("USER");
	if (user_name == NULL){
		fprintf(stderr, "[!] Error grabbing $USER environment variable. Is it set?\n");
		return false;
	}

	/* Yellowish star, green username, white output text. */
	printf("\x1b\x5b\x33\x33\x6d*"
            " \x1b\x5b\x33\x32\x6d%s\x1b\x5b\x33\x39\x6d ", user_name);
    return true;
}

int main(int argc, char **argv)
{

	/* Output user name. */
	if (!print_username()) {
        goto OUT_FAIL;
    }

	if (argc < 2) {
		goto OUT;
    }

	/* Display arguments. */
	for (size_t i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
    }

OUT:
	puts("");
	return EXIT_SUCCESS;

OUT_FAIL:
    return EXIT_FAILURE;
}

