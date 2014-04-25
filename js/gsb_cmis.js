/**
 * Custom JS file for gsb_cmis
 */
(function($){
  Drupal.behaviors.gsbCMIS = {
    attach: function (context, settings) {
    	var nid = settings.alfresco_document.nid;
      var url = Drupal.settings.basePath + 'gsb-cmis/gsb-cmis-get-alfresco-doc/' + nid;
      window.location.replace(url);	
    }
  };
})(jQuery);
