ACLOCAL_AMFLAGS=-I m4
plugindir=@rofi_PLUGIN_INSTALL_DIR@

plugin_LTLIBRARIES = qalc.la

qalc_la_SOURCES=\
		 src/qalc.cpp

qalc_la_CFLAGS= @rofi_CFLAGS@
qalc_la_LIBADD= @rofi_LIBS@
qalc_la_LDFLAGS= -module -avoid-version
