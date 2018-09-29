#include "glmc.h"

inline void glmc_matrix2f_mul_vec2f(vec_2f dest, matrix_src2f matrix_src, vec_2f vec_src){
	dest[0] = matrix_src[0][0]*vec_src[0] + matrix_src[1][0]*vec_src[1];
	dest[1] = matrix_src[0][1]*vec_src[0] + matrix_src[1][1]*vec_src[1];
}

inline void glmc_matrix3f_mul_vec3f(vec_src3f dest, matrix_src3f matrix_src, vec_src3f vec_src){
	dest[0] = matrix_src[0][0]*vec_src[0] + matrix_src[1][0]*vec_src[1] + matrix_src[2][0]*vec_src[2];
	dest[1] = matrix_src[0][1]*vec_src[0] + matrix_src[1][1]*vec_src[1] + matrix_src[2][1]*vec_src[2];
	dest[2] = matrix_src[0][2]*vec_src[0] + matrix_src[1][2]*vec_src[1] + matrix_src[2][2]*vec_src[2];
}

inline void glmc_matrix4f_mul_vec4f(vec_src4f dest, matrix_src4f matrix_src, vec_src4f vec_src){
	dest[0] = matrix_src[0][0]*vec_src[0] + matrix_src[1][0]*vec_src[1] + matrix_src[2][0]*vec_src[2] + matrix_src[3][0]*vec_src[3];
	dest[1] = matrix_src[0][1]*vec_src[0] + matrix_src[1][1]*vec_src[1] + matrix_src[2][1]*vec_src[2] + matrix_src[3][1]*vec_src[3];
	dest[2] = matrix_src[0][2]*vec_src[0] + matrix_src[1][2]*vec_src[1] + matrix_src[2][2]*vec_src[2] + matrix_src[3][2]*vec_src[3];
	dest[3] = matrix_src[0][3]*vec_src[0] + matrix_src[1][3]*vec_src[1] + matrix_src[2][3]*vec_src[2] + matrix_src[3][3]*vec_src[3];
}