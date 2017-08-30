/**
 * Custom JS file for downloading Box file
 */
(function($){
  Drupal.behaviors.gsbBOX = {
    attach: function (context, settings) {
      window.setTimeout(function () {
        var nid = settings.alfresco_document.nid;
        var authtype = settings.alfresco_document.authtype;
        var url = Drupal.settings.basePath + 'gsb-box/gsb-box-get-box-doc/' + nid + '/' + authtype;
        window.location.replace(url);
      }, 1000);
      $('.close-window').bind('click', function(context) {
        window.open('','_self').close();
      });
    }
  };
})(jQuery);
