/* -*- c-file-style: "ruby"; indent-tabs-mode: nil -*- */
/*
 *  Copyright (C) 2011  Ruby-GNOME2 Project Team
 *  Copyright (C) 2005  Masao Mutoh
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA  02110-1301  USA
 */

#include "global.h"
                                                                                
#if GTK_CHECK_VERSION(2,6,0)

static VALUE
filechooserbutton_initialize(int argc, VALUE *argv, VALUE self)
{
    VALUE title, action, backend;
    GtkWidget* widget;

    rb_scan_args(argc, argv, "12", &title, &action, &backend);

    if (TYPE(title) == T_STRING) {
        if (NIL_P(backend)){
            widget = gtk_file_chooser_button_new(RVAL2CSTR(title),
                                                 RVAL2GENUM(action, GTK_TYPE_FILE_CHOOSER_ACTION));
        } else {
            widget = gtk_file_chooser_button_new_with_backend(RVAL2CSTR(title), 
                                                              RVAL2GENUM(action, 
                                                                         GTK_TYPE_FILE_CHOOSER_ACTION),
                                                              RVAL2CSTR(backend));
        }
    } else {
        widget = gtk_file_chooser_button_new_with_dialog(GTK_WIDGET(RVAL2GOBJ(title)));
    }

    RBGTK_INITIALIZE(self, widget);
    return Qnil;
}

/* Defined as Properties
const gchar* gtk_file_chooser_button_get_title
                                            (GtkFileChooserButton *button);
void        gtk_file_chooser_button_set_title
                                            (GtkFileChooserButton *button,
                                             const gchar *title);
gint        gtk_file_chooser_button_get_width_chars
                                            (GtkFileChooserButton *button);
void        gtk_file_chooser_button_set_width_chars
                                            (GtkFileChooserButton *button,
                                             gint n_chars);
gboolean    gtk_file_chooser_button_get_focus_on_click
                                            (GtkFileChooserButton *button);
void        gtk_file_chooser_button_set_focus_on_click
                                            (GtkFileChooserButton *button,
                                             gboolean focus_on_click);
*/

#endif

void 
Init_gtk_filechooserbutton(void)
{
#if GTK_CHECK_VERSION(2,6,0)
    VALUE gFCButton = G_DEF_CLASS(GTK_TYPE_FILE_CHOOSER_BUTTON, "FileChooserButton", mGtk);
    rb_define_method(gFCButton, "initialize", filechooserbutton_initialize, -1);
#endif
}
