/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * GimpTextBuffer
 * Copyright (C) 2010  Michael Natterer <mitch@gimp.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_TEXT_BUFFER_H__
#define __GIMP_TEXT_BUFFER_H__


#define GIMP_TYPE_TEXT_BUFFER            (gimp_text_buffer_get_type ())
#define GIMP_TEXT_BUFFER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_TEXT_BUFFER, GimpTextBuffer))
#define GIMP_IS_TEXT_BUFFER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_TEXT_BUFFER))
#define GIMP_TEXT_BUFFER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_TEXT_BUFFER, GimpTextBufferClass))
#define GIMP_IS_TEXT_BUFFER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_TEXT_BUFFER))


typedef struct _GimpTextBufferClass  GimpTextBufferClass;

struct _GimpTextBuffer
{
  GtkTextBuffer  parent_instance;
};

struct _GimpTextBufferClass
{
  GtkTextBufferClass  parent_class;
};


GType            gimp_text_buffer_get_type       (void) G_GNUC_CONST;

GimpTextBuffer * gimp_text_buffer_new            (void);

void             gimp_text_buffer_set_text       (GimpTextBuffer  *buffer,
                                                  const gchar     *text);
gchar          * gimp_text_buffer_get_text       (GimpTextBuffer  *buffer);

gint             gimp_text_buffer_get_iter_index (GimpTextBuffer  *buffer,
                                                  GtkTextIter     *iter);

gboolean         gimp_text_buffer_load           (GimpTextBuffer  *buffer,
                                                  const gchar     *filename,
                                                  GError         **error);
gboolean         gimp_text_buffer_save           (GimpTextBuffer  *buffer,
                                                  const gchar     *filename,
                                                  gboolean         selection_only,
                                                  GError         **error);


#endif /* __GIMP_TEXT_BUFFER_H__ */