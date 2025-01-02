/*
	Tabulatorweite: 3
	Kommentare ab: Spalte 60											*Spalte 60*
*/

typedef struct _window
{
	struct _window	*next; 												/* Zeiger auf n�chste Struktur */

	WORD	handle;															/* Fensterhandle */
	WORD	kind;																/* Fensterkomponenten */

	GRECT	border;															/* Fensterau�enfl�che */
	GRECT	workarea;														/* Fensterinnenfl�che */
	GRECT	saved_border;													/* bei Iconify gesicherte Fensterau�enfl�che */

	BYTE	*name;															/* Zeiger auf den Fensternamen oder 0L */
	BYTE	*iconified_name;												/* Fenstername f�r ikonifiziertes Fenster oder 0L */
	OBJECT iconified_tree[2];											/* Objektbaum f�r ikonifiziertes Fenster */
	int dirty;		/* redraw notwendig */

	struct
	{
		unsigned           	:	7;										/* reserviert */
		unsigned hide_cursor	:	1;										/* 0: Cursor nicht ausschalten (wird von der Redraw-Routine erledigt) 1: Cursor vor Redraw ausschalten */
		unsigned	snap_width	:	1;										/* Breite auf Vielfache von dx anpassen */
		unsigned	snap_height	:	1;										/* H�he auf Vielfache von dy anpassen */
		unsigned	snap_x		:	1;										/* x-Koordinate auf Vielfache von dx anpassen */
		unsigned	snap_y		:	1;										/* y-Koordinate auf Vielfache von dy anpassen */
		unsigned	smart_size	:	1;										/* Smart Redraw f�rs Sizen */ 
		unsigned	limit_wsize	:	1;										/* maximale Fenstergr��e begrenzen */
		unsigned	fuller		:	1;										/* Fenster hat maximale Gr��e */
		unsigned	iconified	:	1;										/* Fenster ist ikonifiziert */
	} wflags;

	void	(*redraw)( struct _window *window, GRECT *area );	/* Zeiger auf eine Redraw-Routine */
	
	LONG	interior_flags;												/* Art des Inhalts */
	void	*interior;														/* Zeiger auf den Inhalt */

	LONG	x;																	/* x-Koordinate der linken oberen Ecke */
	LONG	y;																	/* y-Koordinate der linken oberen Ecke */
	LONG	w;																	/* Breite der Arbeitsfl�che */
	LONG	h;																	/* H�he der Arbeitsfl�che */

	WORD	dx;																/* Breite einer Scrollspalte in Pixeln */
	WORD	dy;																/* H�he einer Scrollzeile in Pixeln */
	WORD	snap_dx;															/* Vielfaches f�r horizontale Fensterposition */
	WORD	snap_dy;														/* Vielfaches f�r vertikale Fensterposition */
	WORD	snap_dw;															/* Vielfaches der Fensterbreite */
	WORD	snap_dh;															/* Vielfaches der Fensterh�he */
	WORD	limit_w;															/* maximal anzuzeigende Breite der Arbeitsfl�che oder 0 */
	WORD	limit_h;															/* maximal anzuzeigende H�he der Arbeitsfl�che oder 0 */

	WORD	hslide;															/* Position des horizontalen Sliders in Promille */
	WORD	vslide;															/* Position des vertikalen Sliders in Promille */
	WORD	hslsize;															/* Gr��e des horizontalen Sliders in Promille */
	WORD	vslsize;															/* Gr��e des vertikalen Sliders in Promille */

} WINDOW;
