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
  $items['gsb-import-test'] = array(
     'description' => 'GSB Import Test',
     'arguments' => array(
       'uuid' => 'The document uuid',
       'content-type' => 'The content type',
     ),    
     'examples' => array(
       'drush --user=1 gsb-import-test <uuid> <content-type>' => 'Import all docs from a specific Alfresco folder, as the admin user.',
     ),    
     'aliases' => array('gsb-import-test'),
  );     
  return $items;
}

function drush_gsb_cmis_gsb_import_test($uuid = '', $content_type = '') {

  // drush6 gsb-import-test --user=1 urn:uuid qa

  drush_log('test 1 begin -------------','success');

  drush_log('content_type = '.$content_type,'success');

  if ($content_type == 'prod') {
    //prod folder - 
    $object = gsb_cmis_api_getDocumentObject('default', 'urn:uuid:f0afc9f2-eefa-49fc-b6b2-5661b1934985');
  } else {
    // qa item - 
    $object = gsb_cmis_api_getDocumentObject('default', 'urn:uuid:46de00be-f68f-4d90-a05c-cf9213880386');    
  }

  dpm($object);

  drush_log('test 1 done --------------------','success');

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
 * Runs the GSB CMIS Content Type Initial Import command
 */
function drush_gsb_cmis_ct_import($uuid = '', $content_type = '') {

  drush_log(dt('-------------------------------'), 'success');

  if ($uuid == '') {
    drush_log(dt('gsb cmis content type initial import failed - no uuid'), 'error'); 
    return; 
  }

  drush_log(dt('uuid = '.$uuid), 'success'); 

  // $content_type should be 'case' or 'working_paper'
  if ($content_type != 'case' && $content_type != 'working_paper') {
    drush_log(dt('gsb cmis content type initial import failed - invalid content type'), 'error'); 
    return; 
  }

  drush_log(dt('content type = ' . $content_type), 'success'); 

  // run the import
  gsb_cmis_content_type_initial_import($content_type, $uuid);   
  
  drush_log(dt('gsb cmis content type initial import command - completed'), 'ok');  
  
}
