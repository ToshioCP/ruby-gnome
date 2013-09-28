#ifndef __RBPOPPLER_PRIVATE_H__
#define __RBPOPPLER_PRIVATE_H__

#include "rbpoppler.h"

#define RVAL2GDKPIXBUF(o) (GDK_PIXBUF(RVAL2GOBJ(o)))

G_GNUC_INTERNAL void Init_poppler_index_iter(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_font_info(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_document(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_fonts_iter(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_ps_file(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_rectangle(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_page(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_color(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_link_mapping(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_page_transition(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_image_mapping(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_form_field_mapping(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_annotation_mapping(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_attachment(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_action(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_annotation(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_annotation_markup(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_annotation_text(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_annotation_free_text(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_annotation_callout_line(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_form_field(VALUE mPoppler);
G_GNUC_INTERNAL void Init_poppler_button_field(VALUE mPoppler, VALUE cFormField);
G_GNUC_INTERNAL void Init_poppler_text_field(VALUE mPoppler, VALUE cFormField);
G_GNUC_INTERNAL void Init_poppler_choice_field(VALUE mPoppler, VALUE cFormField);

G_GNUC_INTERNAL void rectangle_set(PopplerRectangle *rect, VALUE rb_rect);

#define RECT_ENTITY2RVAL(rect) POPPLERRECTANGLE2RVAL(&(rect))
#define RECT_ENTITY_SET(rect, rb_rect) rectangle_set(&(rect), rb_rect)

#define DEF_READER(prefix, name, member, self_to_c, member_to_rb)       \
static VALUE                                                            \
prefix ## _get_ ## name(VALUE self)                                     \
{                                                                       \
    return member_to_rb((self_to_c(self))->member);                     \
}

#define DEF_WRITER(prefix, name, member, self_to_c, value_to_c) \
static VALUE                                                    \
prefix ## _set_ ## name(VALUE self, VALUE value)                \
{                                                               \
    (self_to_c(self))->member = value_to_c(value);              \
    return Qnil;                                                \
}

#define DEF_WRITER_WITH_SETTER(prefix, name, member,    \
                               self_to_c, value_setter) \
static VALUE                                            \
prefix ## _set_ ## name(VALUE self, VALUE value)        \
{                                                       \
    value_setter((self_to_c(self))->member, value);     \
    return Qnil;                                        \
}

#define DEF_ACCESSOR(prefix, member, self_to_c, member_to_rb, value_to_c) \
    DEF_READER(prefix, member, member, self_to_c, member_to_rb)         \
    DEF_WRITER(prefix, member, member, self_to_c, value_to_c)           \

#define DEF_ACCESSOR_WITH_SETTER(prefix, member, self_to_c,             \
                                 member_to_rb, value_setter)            \
    DEF_READER(prefix, member, member, self_to_c, member_to_rb)         \
    DEF_WRITER_WITH_SETTER(prefix, member, member, self_to_c, value_setter)

#define DEF_ACCESSOR_WITH_NAME(prefix, name, member, self_to_c, \
                               member_to_rb, value_to_c)        \
    DEF_READER(prefix, name, member, self_to_c, member_to_rb)   \
    DEF_WRITER(prefix, name, member, self_to_c, value_to_c)


#endif
