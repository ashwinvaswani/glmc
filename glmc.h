/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _GLMC_H
#define _GLMC_H

#include <stdio.h>
#include <stdint.h>
#include <stdio.h>

// Types:

//For 1D conversions:

typedef float oneD_to_2f[4]; 
typedef float oneD_to_3f[9]; 
typedef float oneD_to_4f[16]; 

//vecor:

typedef float vec2f[2];
typedef float vec3f[3];
typedef float vec4f[4];

//Matrix:

typedef float matrix2f[2][2];
typedef float matrix3f[3][3];
typedef float matrix4f[4][4];

// vec3f

void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b);
void glmc_vec3f_from_4f(vec3f dest, vec4f src);

void glmc_vec3f_copy(vec3f dest, vec3f src);

float glmc_vec3f_sqrlength(vec3f vec);
float glmc_vec3f_length(vec3f vec);

int  glmc_vec3f_is_normalized(vec3f src);
void glmc_vec3f_normlize(vec3f dest, vec3f src);
void glmc_vec3f_normlize_dest(vec3f src_dest);

void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a + src_b;
void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b); // dest += src_a;

void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a - src_b;
void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b); // dest -= src_a;

void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a * src_b;
void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b); // dest *= src_a;
void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b); // dest = src_a * scalar

void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b); // dest = src_a / src_b;
void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b); // dest /= src_a;
void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b); // dest = src_a / scalar

void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a + src_b;
void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a - src_b;

void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b); // dest += src_a * src_b;
void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b); // dest -= src_a * src_b;

float glmc_vec3f_dot(vec3f src_a, vec3f src_b);
void  glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b);

void glmc_vec3f_reflection(vec3f dest, vec3f src, vec3f normal); 
void glmc_vec3f_refraction(vec3f dest, vec3f src, vec3f normal, float src_mu); 

void glmc_vec3f_rotate(vec3f src_a,vec3f src_b,vec3f dest);


// vec4f

void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c);
void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b);

void glmc_vec4f_copy(vec4f dest, vec4f src);

float glmc_vec4f_sqrlength(vec4f vec);
float glmc_vec4f_length(vec4f vec);

int  glmc_vec4f_is_normalized(vec4f src);
void glmc_vec4f_normlize(vec4f dest, vec4f src);
void glmc_vec4f_normlize_dest(vec4f src_dest);


void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a + src_b;
void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b); // dest += src_a;

void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a - src_b;
void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b); // dest -= src_a;

void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a * src_b;
void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b); // dest *= src_a;
void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b); // dest = src_a * scalar

void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b); // dest = src_a / src_b;
void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b); // dest /= src_a;
void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b); // dest = src_a / scalar

void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a + src_b;
void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a - src_b;

void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b); // dest += src_a * src_b;
void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b); // dest -= src_a * src_b;

float glmc_vec4f_dot(vec4f src_a, vec4f src_b);
void glmc_vec4f_rotate(vec4f src_a,vec4f src_b,vec4f dest);

// vec2f

void glmc_vec2f_from_3f(vec2f dest, vec3f src);
void glmc_vec2f_from_4f(vec2f dest, vec2f src);

void glmc_vec2f_copy(vec2f dest, vec2f src);

float glmc_vec2f_sqrlength(vec2f vec);
float glmc_vec2f_length(vec2f vec);

int  glmc_vec2f_is_normalized(vec2f src);
void glmc_vec2f_normlize(vec2f dest, vec2f src);
void glmc_vec3f_normlize_dest(vec2f src_dest);


void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b); 
void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b); 

void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b); 
void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b); 

void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b); 
void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b); 
void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b); 

void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b); 
void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b); 
void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b); 

void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b); 
void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b); 

void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b); 
void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b); 

float glmc_vec2f_dot(vec2f src_a, vec2f src_b);


//matrix2f


void glmc_matrix2f_identity(matrix2f dest); 
void glmc_matrix2f_scale(matrix2f dest, float src_sx); 
void glmc_matrix2f_translation(matrix2f dest, float src_t1); 
void glmc_matrix2f_rotation(matrix2f dest, float theta); 
void glmc_matrix2f_transpose(matrix2f dest, matrix2f src);
void glmc_matrix2f_transpose_dest(matrix2f src_dest);

float glmc_matrix2f_determinant(matrix2f mat);

void glmc_matrix2f_inverse(matrix2f dest, matrix2f src);

void glmc_matrix2f_normlize(matrix2f dest, matrix2f src);
void glmc_matrix2f_normlize_dest(matrix2f src_dest);

void glmc_matrix2f_add(matrix2f dest, matrix2f src_a, matrix2f src_b);
void glmc_matrix2f_add_dest(matrix2f src_dest, matrix2f src_b);

void glmc_matrix2f_sub(matrix2f dest, matrix2f src_a, matrix2f src_b);
void glmc_matrix2f_sub_dest(matrix2f src_dest, matrix2f src_b);

void glmc_matrix2f_mul(matrix2f dest, matrix2f src_a, matrix2f src_b);
void glmc_matrix2f_mul_dest(matrix2f src_dest, matrix2f src_b);
void glmc_matrix2f_mul_s(matrix2f dest, matrix2f src_a, float src_b);

void glmc_matrix2f_div(matrix2f dest, matrix2f src_a, matrix2f src_b);
void glmc_matrix2f_div_dest(matrix2f src_dest, matrix2f src_b);
void glmc_matrix2f_div_s(matrix2f dest, matrix2f src_a, float src_b);

void glmc_matrix2f_addadd(matrix2f dest, matrix2f src_a, matrix2f src_b);
void glmc_matrix2f_subadd(matrix2f dest, matrix2f src_a, matrix2f src_b);

void glmc_matrix2f_madd(matrix2f dest, matrix2f src_a, matrix2f src_b);
void glmc_matrix2f_msub(matrix2f dest, matrix2f src_a, matrix2f src_b);

void glmc_matrix2f_default_normalize(matrix2f dest); 
void glmc_convert_2f_to_1D(oneD_to_2f dest, matrix2f src); 
void glmc_convert_oneD_to_2f(matrix2f dest, oneD_to_2f src); 

//matrix3f

void glmc_matrix3f_identity(matrix3f dest); 
void glmc_matrix3f_scale(matrix3f dest, float src_sx, float src_sy); 
void glmc_matrix3f_translation(matrix3f dest, float src_t1, float src_t2); 
void glmc_matrix3f_rotation(matrix3f dest, float src_ux, float src_uy, float src_uz, float theta); 

void glmc_matrix3f_transpose(matrix3f dest, matrix3f src);
void glmc_matrix3f_transpose_dest(matrix3f src_dest);

float glmc_matrix3f_determinant(matrix3f mat);

void glmc_matrix3f_inverse(matrix3f dest, matrix3f src);

void glmc_matrix3f_normlize(matrix3f dest, matrix3f src);
void glmc_matrix3f_normlize_dest(matrix3f src_dest);

void glmc_matrix3f_add(matrix3f dest, matrix3f src_a, matrix3f src_b);
void glmc_matrix3f_add_dest(matrix3f src_dest, matrix3f src_b);

void glmc_matrix3f_sub(matrix3f dest, matrix3f src_a, matrix3f src_b);
void glmc_matrix3f_sub_dest(matrix3f src_dest, matrix3f src_b);

void glmc_matrix3f_mul(matrix3f dest, matrix3f src_a, matrix3f src_b);
void glmc_matrix3f_mul_dest(matrix3f src_dest, matrix3f src_b);
void glmc_matrix3f_mul_s(matrix3f dest, matrix3f src_a, float src_b);

void glmc_matrix3f_div(matrix3f dest, matrix3f src_a, matrix3f src_b);
void glmc_matrix3f_div_dest(matrix3f src_dest, matrix3f src_b);
void glmc_matrix3f_div_s(matrix3f dest, matrix3f src_a, float src_b);

void glmc_matrix3f_addadd(matrix3f dest, matrix3f src_a, matrix3f src_b);
void glmc_matrix3f_subadd(matrix3f dest, matrix3f src_a, matrix3f src_b);

void glmc_matrix3f_madd(matrix3f dest, matrix3f src_a, matrix3f src_b);
void glmc_matrix3f_msub(matrix3f dest, matrix3f src_a, matrix3f src_b);

void glmc_matrix3f_default_normalize(matrix3f dest); 
void glmc_convert_3f_to_1D(oneD_to_3f dest, matrix3f src); 
void glmc_convert_oneD_to_3f(matrix3f dest, oneD_to_3f src); 

//matrix4f

void glmc_matrix4f_identity(matrix4f dest); 
void glmc_matrix4f_scale(matrix4f dest, float src_sx, float src_sy, float src_sz); 
void glmc_matrix4f_translation(matrix4f dest, float src_t1, float src_t2, float src_t3); 
void glmc_matrix4f_rotation(matrix4f dest, float src_ux, float src_uy, float src_uz, float theta); 

void glmc_matrix4f_transpose(matrix4f dest, matrix4f src);
void glmc_matrix4f_transpose_dest(matrix4f src_dest);

float glmc_matrix4f_determinant(matrix4f mat);

void glmc_matrix4f_inverse(matrix4f dest, matrix4f src);

void glmc_matrix4f_normlize(matrix4f dest, matrix4f src);
void glmc_matrix4f_normlize_dest(matrix4f src_dest);

void glmc_matrix4f_add(matrix4f dest, matrix4f src_a, matrix4f src_b);
void glmc_matrix4f_add_dest(matrix4f src_dest, matrix4f src_b);

void glmc_matrix4f_sub(matrix4f dest, matrix4f src_a, matrix4f src_b);
void glmc_matrix4f_sub_dest(matrix4f src_dest, matrix4f src_b);

void glmc_matrix4f_mul(matrix4f dest, matrix4f src_a, matrix4f src_b);
void glmc_matrix4f_mul_dest(matrix4f src_dest, matrix4f src_b);
void glmc_matrix4f_mul_s(matrix4f dest, matrix4f src_a, float src_b);

void glmc_matrix4f_div(matrix4f dest, matrix4f src_a, matrix4f src_b);
void glmc_matrix4f_div_dest(matrix4f src_dest, matrix4f src_b);
void glmc_matrix4f_div_s(matrix4f dest, matrix4f src_a, float src_b);

void glmc_matrix4f_addadd(matrix4f dest, matrix4f src_a, matrix4f src_b);
void glmc_matrix4f_subadd(matrix4f dest, matrix4f src_a, matrix4f src_b);

void glmc_matrix4f_madd(matrix4f dest, matrix4f src_a, matrix4f src_b);
void glmc_matrix4f_msub(matrix4f dest, matrix4f src_a, matrix4f src_b);

void glmc_matrix4f_perspective_projection(matrix4f dest, float src_fovy, float src_aspect, float src_zNear, float src_zFar);
void glmc_matrix4f_ortho_projection(matrix4f dest, float src_left, float src_right, float src_bottom, float src_top);

void glmc_matrix4f_default_normalize(matrix4f dest); 
void glmc_convert_4f_to_1D(oneD_to_4f dest, matrix4f src); 
void glmc_convert_oneD_to_4f(matrix4f dest, oneD_to_4f src); 

//matrix_vecor

void glmc_matrix2f_mul_vec2f(vec2f dest, matrix2f mat, vec2f vec);
void glmc_matrix3f_mul_vec3f(vec3f dest, matrix3f mat, vec3f vec);
void glmc_matrix4f_mul_vec4f(vec4f dest, matrix4f mat, vec4f vec);

#endif /* _GLMC_H */
