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
    'arguments' => array(
      'uuid' => 'The document uuid',
      'content-type' => 'The content type',
    ),    
    'examples' => array(
      'drush --user=1 gsbcmis-ctimport <uuid> <content-type>' => 'Import all docs from a specific Alfresco folder, as the admin user.',
    ),    
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
function drush_gsb_cmis_ct_import($uuid = '', $content_type = '') {

  if ($uuid == '') {
    drush_log(dt('gsb cmis content type initial import failed - no uuid'), 'error'); 
    return; 
  }

  dpm('uuid = ' . $uuid);

  // $content_type should be 'case' or 'working_paper'
  if ($content_type != 'case' && $content_type != 'working_paper') {
    drush_log(dt('gsb cmis content type initial import failed - invalid content type'), 'error'); 
    return; 
  }

  dpm('content type = ' . $content_type);

  gsb_cmis_content_type_initial_import($content_type, $uuid);   
  
  // log to the command line with an OK status
  drush_log(dt('gsb cmis content type initial import command - completed'), 'ok');  
  
}

