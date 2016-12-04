#include <check.h>
#include <stdlib.h>
#include "between_two_sets.h"

START_TEST(test_findGCD_in_A)
{
	int *a[5] = {2, 4, 8, 16, 37};
	ck_assert_int_eq(findGCD_inA(a), 16);
}
END_TEST

Suite * between_suite(void)
{
	Suite *s;
	TCase * betweenTest;

	s = suite_create("Between");

	betweenTest = tcase_create("Core");
	tcase_add_test(betweenTest, test_findGCD_in_A);

	suite_add_tcase(s, betweenTest);

	return s;
}

int main()
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = between_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
