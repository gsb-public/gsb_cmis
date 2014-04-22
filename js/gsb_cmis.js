/**
 * Custom JS file for gsb_cmis
 */
(function($){
  Drupal.behaviors.gsbCMIS = {
    attach: function (context, settings) {
    	var uuid = settings.alfresco_document.uuid;
      var url = Drupal.settings.basePath + 'gsb-cmis/gsb-cmis-get-alfresco-doc/' + uuid;
      window.location.replace(url);	
    }
  };
})(jQuery);
