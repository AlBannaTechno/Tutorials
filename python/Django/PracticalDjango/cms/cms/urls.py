from django.conf.urls import patterns, include, url

from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    url(r'^admin/doc/', include('django.contrib.admindocs.urls')),
    url(r'^admin/', include(admin.site.urls)),
    url(r'^tiny_mce/(?P<path>.*)$', 'django.views.static.serve', {'document_root':
      ('C:/Users/NDonais/Dropbox/Programming/python_projects/Tutorials/Django/PracticalDjango'
       '/cms/tiny_mce')}),
    url(r'^search/$', 'cms.search.views.search'),
    url(r'', include('django.contrib.flatpages.urls')),
)
