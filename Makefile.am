ACLOCAL_AMFLAGS=-I m4
plugindir=@rofi_PLUGIN_INSTALL_DIR@

plugin_LTLIBRARIES = qalc.la

qalc_la_SOURCES= src/qalc.cpp

# TODO: Remove glib and cairo once the below change lands:
# https://github.com/DaveDavenport/rofi/pull/848
qalc_la_CXXFLAGS= @rofi_CFLAGS@ @QALCULATE_CFLAGS@ @glib_CFLAGS@ @cairo_CFLAGS@
qalc_la_LIBADD= @rofi_LIBS@ @QALCULATE_LIBS@ @glib_LIBS@ @cairo_LIBS@
qalc_la_LDFLAGS= -module -avoid-version
