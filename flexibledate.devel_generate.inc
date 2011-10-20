<?php

/**
 * Provides Devel generate integration for the flexibledate field type.
 */

/**
 * Implements hook_devel_generate().
 */
function flexibledate_devel_generate($object, $field, $instance, $bundle) {
  // Leave some fields empty, if they are not required.
  if (empty($instance['required']) && rand(0, 5) == 0) {
    return;
  }

  // Return a random field value item.
  switch (rand(0, 2)) {
    case FLEXIBLEDATE_DATE:
      return Flexibledate::createFromDate(rand(1, 31), rand(1, 12), rand(1990, date('Y') + 5))->toItem();
    case FLEXIBLEDATE_QUARTER:
      return Flexibledate::createFromQuarter(rand(1, 4), rand(1930, date('Y') + 10))->toItem();
    case FLEXIBLEDATE_YEAR:
      return Flexibledate::createFromYear(rand(1920, date('Y') + 50))->toItem();
  }
}
