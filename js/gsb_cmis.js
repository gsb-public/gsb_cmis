/**
 * Custom JS file for gsb_cmis
 */
(function($){
  Drupal.behaviors.gsbCMIS = {
    attach: function (context, settings) {
    	var uuid = settings.alfresco_document.uuid;
      var url = Drupal.settings.basePath + 'gsb-cmis/gsb_cmis_get_alfresco_doc/' + uuid;
      window.location.replace(url);	
    }
  };
})(jQuery);