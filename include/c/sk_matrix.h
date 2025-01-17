/*
 * Copyright 2014 Google Inc.
 * Copyright 2015 Xamarin Inc.
 * Copyright 2017 Microsoft Corporation. All rights reserved.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef sk_matrix_DEFINED
#define sk_matrix_DEFINED

#include "include/c/sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD


SK_C_API bool sk_matrix_try_invert (sk_matrix_t *matrix, sk_matrix_t *result);
SK_C_API void sk_matrix_concat (sk_matrix_t *result, sk_matrix_t *first, sk_matrix_t *second);
SK_C_API void sk_matrix_pre_concat (sk_matrix_t *result, sk_matrix_t *matrix);
SK_C_API void sk_matrix_post_concat (sk_matrix_t *result, sk_matrix_t *matrix);
SK_C_API void sk_matrix_map_rect (sk_matrix_t *matrix, sk_rect_t *dest, sk_rect_t *source);
SK_C_API void sk_matrix_map_points (sk_matrix_t *matrix, sk_point_t *dst, sk_point_t *src, int count);
SK_C_API void sk_matrix_map_vectors (sk_matrix_t *matrix, sk_point_t *dst, sk_point_t *src, int count);
SK_C_API void sk_matrix_map_xy (sk_matrix_t *matrix, float x, float y, sk_point_t* result);
SK_C_API void sk_matrix_map_vector (sk_matrix_t *matrix, float x, float y, sk_point_t* result);
SK_C_API float sk_matrix_map_radius (sk_matrix_t *matrix, float radius);
// additional
SK_C_API sk_matrix_t sk_matrix_scale(float sx, float sy);
SK_C_API sk_matrix_t sk_matrix_translate(float dx, float dy);
SK_C_API sk_matrix_t sk_matrix_translate_point(sk_point_t t);
SK_C_API sk_matrix_t sk_matrix_translate_ipoint(sk_ipoint_t t);
SK_C_API sk_matrix_t sk_matrix_rotate_deg(float deg);
SK_C_API sk_matrix_t sk_matrix_rotate_deg_point(float deg, sk_point_t t);
SK_C_API sk_matrix_t sk_matrix_rotate_rad(float rad);
SK_C_API sk_matrix_type_mask_t sk_matrix_get_type(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_is_identity(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_is_scale_translate(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_is_translate(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_rect_stays_rect(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_preserves_axis_alignment(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_has_perspective(sk_matrix_t* matrix);
SK_C_API bool sk_matrix_is_similarity(sk_matrix_t* matrix, float tol);
SK_C_API bool sk_matrix_preserves_right_angles(sk_matrix_t* matrix, float tol);
SK_C_API float sk_matrix_get(sk_matrix_t* matrix, sk_matrix_row_major_mask_t mask);
SK_C_API float sk_matrix_rc(sk_matrix_t* matrix, int r, int c);
SK_C_API void sk_matrix_get9(sk_matrix_t* matrix, float* buffer);
SK_C_API void sk_matrix_set9(sk_matrix_t* matrix, float* buffer, sk_matrix_t* result);
SK_C_API void sk_matrix_reset(sk_matrix_t* matrix, sk_matrix_t* result);
SK_C_API void sk_matrix_set_identity(sk_matrix_t* matrix, sk_matrix_t* result);
SK_C_API void sk_matrix_normalize_perspective(sk_matrix_t* matrix, sk_matrix_t* result);
SK_C_API void sk_matrix_map_homogeneous_points3(sk_matrix_t* matrix, sk_point3_t* dst, sk_point3_t* src, int count);
SK_C_API void sk_matrix_map_homogeneous_points(sk_matrix_t* matrix, sk_point3_t* dst, sk_point_t* src, int count);
SK_C_API bool sk_matrix_is_finite(sk_matrix_t* matrix);
SK_C_API void sk_matrix_pre_scale(sk_matrix_t* result, sk_matrix_t* matrix, float sx, float sy);
SK_C_API void sk_matrix_pre_scale_with_pivot(sk_matrix_t* result, sk_matrix_t* matrix, float sx, float sy, float px, float py);
SK_C_API void sk_matrix_post_scale(sk_matrix_t* result, sk_matrix_t* matrix, float sx, float sy);
SK_C_API void sk_matrix_post_scale_with_pivot(sk_matrix_t* result, sk_matrix_t* matrix, float sx, float sy, float px, float py);
SK_C_API void sk_matrix_pre_translate(sk_matrix_t* result, sk_matrix_t* matrix, float dx, float dy);
SK_C_API void sk_matrix_post_translate(sk_matrix_t* result, sk_matrix_t* matrix, float dx, float dy);
SK_C_API bool sk_matrix_set_rect_to_rect(sk_matrix_t* matrix, sk_matrix_t* result, sk_rect_t* dest, sk_rect_t* source, sk_matrix_scale_to_fit_t stf);



SK_C_API sk_3dview_t* sk_3dview_new (void);
SK_C_API void sk_3dview_destroy (sk_3dview_t* cview);
SK_C_API void sk_3dview_save (sk_3dview_t* cview);
SK_C_API void sk_3dview_restore (sk_3dview_t* cview);
SK_C_API void sk_3dview_translate (sk_3dview_t* cview, float x, float y, float z);
SK_C_API void sk_3dview_rotate_x_degrees (sk_3dview_t* cview, float degrees);
SK_C_API void sk_3dview_rotate_y_degrees (sk_3dview_t* cview, float degrees);
SK_C_API void sk_3dview_rotate_z_degrees (sk_3dview_t* cview, float degrees);
SK_C_API void sk_3dview_rotate_x_radians (sk_3dview_t* cview, float radians);
SK_C_API void sk_3dview_rotate_y_radians (sk_3dview_t* cview, float radians);
SK_C_API void sk_3dview_rotate_z_radians (sk_3dview_t* cview, float radians);
SK_C_API void sk_3dview_get_matrix (sk_3dview_t* cview, sk_matrix_t* cmatrix);
SK_C_API void sk_3dview_apply_to_canvas (sk_3dview_t* cview, sk_canvas_t* ccanvas);
SK_C_API float sk_3dview_dot_with_normal (sk_3dview_t* cview, float dx, float dy, float dz);


SK_C_API void sk_m44_destroy (sk_m44_t* matrix);
SK_C_API sk_m44_t* sk_m44_new (void);
SK_C_API sk_m44_t* sk_m44_new_identity (void);
SK_C_API sk_m44_t* sk_m44_new_copy (const sk_m44_t* src);
SK_C_API sk_m44_t* sk_m44_new_concat (const sk_m44_t* a, const sk_m44_t* b);
SK_C_API sk_m44_t* sk_m44_new_matrix (const sk_matrix_t* src);
SK_C_API bool sk_m44_equals (sk_m44_t* matrix, const sk_m44_t* other);
SK_C_API void sk_m44_to_matrix (sk_m44_t* matrix, sk_matrix_t* dst);
SK_C_API void sk_m44_set_identity (sk_m44_t* matrix);
SK_C_API float sk_m44_get (sk_m44_t* matrix, int row, int col);
SK_C_API void sk_m44_set (sk_m44_t* matrix, int row, int col, float value);
SK_C_API void sk_m44_as_col_major (sk_m44_t* matrix, float* dst);
SK_C_API void sk_m44_as_row_major (sk_m44_t* matrix, float* dst);
SK_C_API void sk_m44_set_col_major (sk_m44_t* matrix, float* dst);
SK_C_API void sk_m44_set_row_major (sk_m44_t* matrix, float* dst);
SK_C_API void sk_m44_set_3x3_row_major (sk_m44_t* matrix, float* dst);
SK_C_API void sk_m44_set_translate (sk_m44_t* matrix, float dx, float dy, float dz);
SK_C_API void sk_m44_pre_translate (sk_m44_t* matrix, float dx, float dy, float dz);
SK_C_API void sk_m44_post_translate (sk_m44_t* matrix, float dx, float dy, float dz);
SK_C_API void sk_m44_set_scale (sk_m44_t* matrix, float sx, float sy, float sz);
SK_C_API void sk_m44_pre_scale (sk_m44_t* matrix, float sx, float sy, float sz);
SK_C_API void sk_m44_post_scale (sk_m44_t* matrix, float sx, float sy, float sz);
SK_C_API void sk_m44_set_rotate_about_degrees (sk_m44_t* matrix, float x, float y, float z, float degrees);
SK_C_API void sk_m44_set_rotate_about_radians (sk_m44_t* matrix, float x, float y, float z, float radians);
SK_C_API void sk_m44_set_rotate_about_radians_unit (sk_m44_t* matrix, float x, float y, float z, float radians);
SK_C_API void sk_m44_set_concat (sk_m44_t* matrix, const sk_m44_t* a, const sk_m44_t* b);
SK_C_API void sk_m44_pre_concat (sk_m44_t* matrix, const sk_m44_t* m);
SK_C_API void sk_m44_post_concat (sk_m44_t* matrix, const sk_m44_t* m);
SK_C_API bool sk_m44_invert (sk_m44_t* matrix, sk_m44_t* inverse);
SK_C_API void sk_m44_transpose (sk_m44_t* matrix);
SK_C_API void sk_m44_map_scalars (sk_m44_t* matrix, const float* src, float* dst);
SK_C_API void sk_m44_map2 (sk_m44_t* matrix, const float* src2, int count, float* dst4);
SK_C_API bool sk_m44_preserves_2d_axis_alignment (sk_m44_t* matrix, float epsilon);
SK_C_API double sk_m44_determinant (sk_m44_t* matrix);


SK_C_PLUS_PLUS_END_GUARD

#endif
