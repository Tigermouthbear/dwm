void
loadxrdb()
{
	Display *display;
	char * resm;
	XrmDatabase xrdb;
	char *type;
	XrmValue value;

	display = XOpenDisplay(NULL);

	if (display != NULL) {
		resm = XResourceManagerString(display);

		if (resm != NULL) {
			xrdb = XrmGetStringDatabase(resm);

			if (xrdb != NULL) {
				/* OLD COLORS
                XRDB_LOAD_COLOR("dwm.color15", normfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", normbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", normbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", normfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", selfgcolor);
				XRDB_LOAD_COLOR("dwm.color2", selbgcolor);
				XRDB_LOAD_COLOR("dwm.color2", selbordercolor);
				XRDB_LOAD_COLOR("dwm.color2", selfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.color2", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.color2", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.color2", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.color2", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.color2", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.color2", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color2", hidnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color3", hidselfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidselbgcolor);
				XRDB_LOAD_COLOR("dwm.color15", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.urgbordercolor", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", urgfloatcolor);*/

                XRDB_LOAD_COLOR("dwm.color7", normfgcolor);
                XRDB_LOAD_COLOR("dwm.color0", normbgcolor);
                XRDB_LOAD_COLOR("dwm.color8", normbordercolor);
                XRDB_LOAD_COLOR("dwm.color8", normfloatcolor);
                XRDB_LOAD_COLOR("dwm.color7", selfgcolor);
                XRDB_LOAD_COLOR("dwm.color2", selbgcolor);
                XRDB_LOAD_COLOR("dwm.color7", selbordercolor);
                XRDB_LOAD_COLOR("dwm.color7", selfloatcolor);

                XRDB_LOAD_COLOR("dwm.color15", titlenormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", titlenormbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", titlenormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", titleselfgcolor);
				XRDB_LOAD_COLOR("dwm.color2", titleselbgcolor);
				XRDB_LOAD_COLOR("dwm.color2", titleselbordercolor);
				XRDB_LOAD_COLOR("dwm.color2", titleselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", tagsnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color8", tagsnormbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", tagsnormfloatcolor);
				XRDB_LOAD_COLOR("dwm.color15", tagsselfgcolor);
				XRDB_LOAD_COLOR("dwm.color2", tagsselbgcolor);
				XRDB_LOAD_COLOR("dwm.color2", tagsselbordercolor);
				XRDB_LOAD_COLOR("dwm.color2", tagsselfloatcolor);
				XRDB_LOAD_COLOR("dwm.color2", hidnormfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidnormbgcolor);
				XRDB_LOAD_COLOR("dwm.color3", hidselfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", hidselbgcolor);
				XRDB_LOAD_COLOR("dwm.color15", urgfgcolor);
				XRDB_LOAD_COLOR("dwm.color0", urgbgcolor);
				XRDB_LOAD_COLOR("dwm.urgbordercolor", urgbordercolor);
				XRDB_LOAD_COLOR("dwm.color8", urgfloatcolor);

                /*XRDB_LOAD_COLOR("dwm.color0", titlenormfgcolor);
                XRDB_LOAD_COLOR("dwm.color0", titlenormbgcolor);
                XRDB_LOAD_COLOR("dwm.color8", titlenormbordercolor);
                XRDB_LOAD_COLOR("dwm.color13", titlenormfloatcolor);

                XRDB_LOAD_COLOR("dwm.color0", titleselfgcolor);
                XRDB_LOAD_COLOR("dwm.color14", titleselbgcolor);
                XRDB_LOAD_COLOR("dwm.color7", titleselbordercolor);
                XRDB_LOAD_COLOR("dwm.color0", titleselfloatcolor);

                XRDB_LOAD_COLOR("dwm.color7", tagsnormfgcolor);
                XRDB_LOAD_COLOR("dwm.color0", tagsnormbgcolor);
                XRDB_LOAD_COLOR("dwm.color8", tagsnormbordercolor);
                XRDB_LOAD_COLOR("dwm.color13", tagsnormfloatcolor);

                XRDB_LOAD_COLOR("dwm.color0", tagsselfgcolor);
                XRDB_LOAD_COLOR("dwm.color14", tagsselbgcolor);
                XRDB_LOAD_COLOR("dwm.color7", tagsselbordercolor);
                XRDB_LOAD_COLOR("dwm.color2", tagsselfloatcolor);

                XRDB_LOAD_COLOR("dwm.color2", hidnormfgcolor);
                XRDB_LOAD_COLOR("dwm.color5", hidselfgcolor);
                XRDB_LOAD_COLOR("dwm.color0", hidnormbgcolor);
                XRDB_LOAD_COLOR("dwm.color0", hidselbgcolor);

                XRDB_LOAD_COLOR("dwm.color7", urgfgcolor);
                XRDB_LOAD_COLOR("dwm.color0", urgbgcolor);
                XRDB_LOAD_COLOR("dwm.color1", urgbordercolor);
                XRDB_LOAD_COLOR("dwm.color13", urgfloatcolor);*/

				#if RENAMED_SCRATCHPADS_PATCH
				XRDB_LOAD_COLOR("dwm.scratchselfgcolor", scratchselfgcolor);
				XRDB_LOAD_COLOR("dwm.scratchselbgcolor", scratchselbgcolor);
				XRDB_LOAD_COLOR("dwm.scratchselbordercolor", scratchselbordercolor);
				XRDB_LOAD_COLOR("dwm.scratchselfloatcolor", scratchselfloatcolor);
				XRDB_LOAD_COLOR("dwm.scratchnormfgcolor", scratchnormfgcolor);
				XRDB_LOAD_COLOR("dwm.scratchnormbgcolor", scratchnormbgcolor);
				XRDB_LOAD_COLOR("dwm.scratchnormbordercolor", scratchnormbordercolor);
				XRDB_LOAD_COLOR("dwm.scratchnormfloatcolor", scratchnormfloatcolor);
				#endif // RENAMED_SCRATCHPADS_PATCH
				#if BAR_FLEXWINTITLE_PATCH
				XRDB_LOAD_COLOR("dwm.normTTBbgcolor", normTTBbgcolor);
				XRDB_LOAD_COLOR("dwm.normLTRbgcolor", normLTRbgcolor);
				XRDB_LOAD_COLOR("dwm.normMONObgcolor", normMONObgcolor);
				XRDB_LOAD_COLOR("dwm.normGRIDbgcolor", normGRIDbgcolor);
				XRDB_LOAD_COLOR("dwm.normGRD1bgcolor", normGRD1bgcolor);
				XRDB_LOAD_COLOR("dwm.normGRD2bgcolor", normGRD2bgcolor);
				XRDB_LOAD_COLOR("dwm.normGRDMbgcolor", normGRDMbgcolor);
				XRDB_LOAD_COLOR("dwm.normHGRDbgcolor", normHGRDbgcolor);
				XRDB_LOAD_COLOR("dwm.normDWDLbgcolor", normDWDLbgcolor);
				XRDB_LOAD_COLOR("dwm.normSPRLbgcolor", normSPRLbgcolor);
				XRDB_LOAD_COLOR("dwm.normfloatbgcolor", normfloatbgcolor);
				XRDB_LOAD_COLOR("dwm.actTTBbgcolor", actTTBbgcolor);
				XRDB_LOAD_COLOR("dwm.actLTRbgcolor", actLTRbgcolor);
				XRDB_LOAD_COLOR("dwm.actMONObgcolor", actMONObgcolor);
				XRDB_LOAD_COLOR("dwm.actGRIDbgcolor", actGRIDbgcolor);
				XRDB_LOAD_COLOR("dwm.actGRD1bgcolor", actGRD1bgcolor);
				XRDB_LOAD_COLOR("dwm.actGRD2bgcolor", actGRD2bgcolor);
				XRDB_LOAD_COLOR("dwm.actGRDMbgcolor", actGRDMbgcolor);
				XRDB_LOAD_COLOR("dwm.actHGRDbgcolor", actHGRDbgcolor);
				XRDB_LOAD_COLOR("dwm.actDWDLbgcolor", actDWDLbgcolor);
				XRDB_LOAD_COLOR("dwm.actSPRLbgcolor", actSPRLbgcolor);
				XRDB_LOAD_COLOR("dwm.actfloatbgcolor", actfloatbgcolor);
				XRDB_LOAD_COLOR("dwm.selTTBbgcolor", selTTBbgcolor);
				XRDB_LOAD_COLOR("dwm.selLTRbgcolor", selLTRbgcolor);
				XRDB_LOAD_COLOR("dwm.selMONObgcolor", selMONObgcolor);
				XRDB_LOAD_COLOR("dwm.selGRIDbgcolor", selGRIDbgcolor);
				XRDB_LOAD_COLOR("dwm.selGRD1bgcolor", selGRD1bgcolor);
				XRDB_LOAD_COLOR("dwm.selGRD2bgcolor", selGRD2bgcolor);
				XRDB_LOAD_COLOR("dwm.selGRDMbgcolor", selGRDMbgcolor);
				XRDB_LOAD_COLOR("dwm.selHGRDbgcolor", selHGRDbgcolor);
				XRDB_LOAD_COLOR("dwm.selDWDLbgcolor", selDWDLbgcolor);
				XRDB_LOAD_COLOR("dwm.selSPRLbgcolor", selSPRLbgcolor);
				XRDB_LOAD_COLOR("dwm.selfloatbgcolor", selfloatbgcolor);
				#endif // BAR_FLEXWINTITLE_PATCH
				#if BAR_STATUS2D_XRDB_TERMCOLORS_PATCH && BAR_STATUS2D_PATCH
				XRDB_LOAD_COLOR("color0", termcol0);
				XRDB_LOAD_COLOR("color1", termcol1);
				XRDB_LOAD_COLOR("color2", termcol2);
				XRDB_LOAD_COLOR("color3", termcol3);
				XRDB_LOAD_COLOR("color4", termcol4);
				XRDB_LOAD_COLOR("color5", termcol5);
				XRDB_LOAD_COLOR("color6", termcol6);
				XRDB_LOAD_COLOR("color7", termcol7);
				XRDB_LOAD_COLOR("color8", termcol8);
				XRDB_LOAD_COLOR("color9", termcol9);
				XRDB_LOAD_COLOR("color10", termcol10);
				XRDB_LOAD_COLOR("color11", termcol11);
				XRDB_LOAD_COLOR("color12", termcol12);
				XRDB_LOAD_COLOR("color13", termcol13);
				XRDB_LOAD_COLOR("color14", termcol14);
				XRDB_LOAD_COLOR("color15", termcol15);
				#endif // BAR_STATUS2D_XRDB_TERMCOLORS_PATCH

				XrmDestroyDatabase(xrdb);
			}
		}
	}

	XCloseDisplay(display);
}

void
xrdb(const Arg *arg)
{
	loadxrdb();
	int i;
	for (i = 0; i < LENGTH(colors); i++)
		scheme[i] = drw_scm_create(drw, colors[i],
		#if BAR_ALPHA_PATCH
		alphas[i],
		#endif // BAR_ALPHA_PATCH
		ColCount
		);
	focus(NULL);
	arrange(NULL);
}

