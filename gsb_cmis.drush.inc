<?php

/**
 * @file
 * Drush commands for GSB CMIS Test
 */

/**
 * Implements hook_drush_command().
 */
function gsb_cmis_drush_command() {
  $items = array();
  $items['gsb-cmis-ct-import'] = array(
    'description' => 'GSB CMIS Content Type Initial Import',
    'aliases' => array('gsbcmis-ctimport'),
  ); 
  return $items;
}

/**
 * Implement hook_drush_help().
 */
function gsb_cmis_drush_help($command) {
  switch ($command) {
    case 'drush:gsb-cmis-ct-import':
      return dt('Run cmis content type initial import command');
  }
}

/**
 * Runs the gsb cmsi test doit command
 */
function drush_gsb_cmis_ct_import() {
  
  $content_type = 'case';
  gsb_cmis_test_content_type_initial_import(
    $content_type, 
    // QA - Greg (test) folder
    //46de00be-f68f-4d90-a05c-cf9213880386
    'urn:uuid:46de00be-f68f-4d90-a05c-cf9213880386'
  ); 
  
  // log to the command line with an OK status
  drush_log(dt('gsb cmis content type initial import command complete'), 'ok');  
  
}

