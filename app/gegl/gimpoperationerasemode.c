/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * gimpoperationerasemode.c
 * Copyright (C) 2008 Michael Natterer <mitch@gimp.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"

#include <gegl.h>

#include "gegl-types.h"

#include "gimpoperationerasemode.h"


static gboolean gimp_operation_erase_mode_process (GeglOperation       *operation,
                                                   void                *in_buf,
                                                   void                *aux_buf,
                                                   void                *out_buf,
                                                   glong                samples,
                                                   const GeglRectangle *roi);


G_DEFINE_TYPE (GimpOperationEraseMode, gimp_operation_erase_mode,
               GIMP_TYPE_OPERATION_POINT_COMPOSER)


static void
gimp_operation_erase_mode_class_init (GimpOperationEraseModeClass *klass)
{
  GeglOperationClass              *operation_class = GEGL_OPERATION_CLASS (klass);
  GeglOperationPointComposerClass *point_class     = GEGL_OPERATION_POINT_COMPOSER_CLASS (klass);

  operation_class->name        = "gimp-erase-mode";
  operation_class->description = "GIMP erase mode operation";

  point_class->process         = gimp_operation_erase_mode_process;
}

static void
gimp_operation_erase_mode_init (GimpOperationEraseMode *self)
{
}

static gboolean
gimp_operation_erase_mode_process (GeglOperation       *operation,
                                   void                *in_buf,
                                   void                *aux_buf,
                                   void                *out_buf,
                                   glong                samples,
                                   const GeglRectangle *roi)
{
  gfloat *src  = in_buf;
  gfloat *aux  = aux_buf;
  gfloat *dest = out_buf;

  while (samples--)
    {
      dest[RED_PIX]   = src[RED_PIX];
      dest[GREEN_PIX] = src[GREEN_PIX];
      dest[BLUE_PIX]  = src[BLUE_PIX];
      dest[ALPHA_PIX] = src[ALPHA_PIX];

      src  += 4;
      aux  += 4;
      dest += 4;
    }

  return TRUE;
}