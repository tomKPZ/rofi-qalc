ACLOCAL_AMFLAGS=-I m4
plugindir=@rofi_PLUGIN_INSTALL_DIR@

plugin_LTLIBRARIES = qalc.la

dict_la_SOURCES=\
		 src/qalc.cpp

dict_la_CFLAGS= @rofi_CFLAGS@
dict_la_LIBADD= @rofi_LIBS@
dict_la_LDFLAGS= -module -avoid-version
