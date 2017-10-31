CONTIKI_PROJECT = tr16-badge
all: $(CONTIKI_PROJECT)

CONTIKI = ../..
include $(CONTIKI)/Makefile.include

ifdef GROUP
	CFLAGS+="-DGROUP='${GROUP}'"
endif

ifdef NAME
	CFLAGS+="-DNAME=\"${NAME}\""
endif

ifdef FNAME
	CFLAGS+="-DFNAME=\"${FNAME}\""
endif

ifdef TOKEN
	CFLAGS+="-DTOKEN=\"${TOKEN}\""
endif

ifdef ID
	CFLAGS+="-DID=${ID}"
endif
