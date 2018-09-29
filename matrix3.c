#include "glmc.h"

inline void glmc_matrix3f_identity(matrix3f dest) { 

	dest[0][0] = 1.0f; 
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = 1.0f; 
	dest[1][2] = 0; 
	dest[2][0] = 0; 
	dest[2][1] = 0; 
	dest[2][2] = 1.0f; 
} 

inline void glmc_matrix3f_scale(matrix3f dest, float src_sx, float src_sy) { 
	dest[0][0] = src_sx; 
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = src_sy; 
	dest[1][2] = 0; 
	dest[2][0] = 0; 
	dest[2][1] = 0; 
	dest[2][2] = 1.0f; 
} 
 
inline void glmc_matrix3f_translation(matrix3f dest, float src_t1, float src_t2) { 
	dest[0][0] = 1.0f;  
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = 1.0f; 
	dest[1][2] = 0; 
	dest[2][0] = src_ti; 
	dest[2][1] = src_t2; 
	dest[2][2] = 1.0f;
} 

inline void glmc_matrix3f_rotation(matrix3f dest, float src_ux, float src_uy, float src_uz, float theta)  { 
	float c = cos(theta); 
	float s = sin(theta); 
	dest[0][0] = c + src_ux*src_ux*(1-c); 
	dest[0][1] = src_uy*src_ux*(1-c) + src_uz*s; 
	dest[0][2] = src_uz*src_ux*(1-c) - src_uy*s; 
	dest[1][0] = src_ux*src_uy*(1-c) - src_uz*s; 
	dest[1][1] = c + src_uy*src_uy*(1-c); 
	dest[1][2] = src_uz*src_uy*(1-c) + src_ux*(s); 
	dest[2][0] = src_ux*src_uz*(1-c) + src_uy*s; 
	dest[2][1] = src_uy*src_uz*(1-c) - src_ux*s; 
	dest[2][2] = c + src_uz*src_uz*(1-c); 
}

inline void glmc_matrix3f_transpose(matrix3f dest, matrix3f src){
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[0][2] = src[2][0];
	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
	dest[1][2] = src[2][1];
	dest[2][0] = src[0][2];
	dest[2][1] = src[1][2];
	dest[2][2] = src[2][2];
}

inline void glmc_matrix3f_transpose_dest(matrix3f src_dest){
	float temp;
	temp = src_dest[0][1];
	src_dest[0][1] = src_dest[1][0];
	src_dest[1][0] = temp;
	temp = src_dest[0][2];
	src_dest[0][2] = src_dest[2][0];
	src_dest[2][0] = temp;
	temp = src_dest[1][2];
	src_dest[1][2] = src_dest[2][1];
	src_dest[2][1] = temp;
}

inline float glmc_matrix3f_determinant(matrix3f mat){
	float matrix3f_det;
	matrix3f_det = + (mat[0][0]*((mat[1][1]*mat[2][2])-(mat[2][1]*mat[1][2]))) 
				- (mat[1][0]*((mat[0][1]*mat[2][2])-(mat[2][1]*mat[0][2]))) 
				+ (mat[2][0]*((mat[0][1]*mat[1][2])-(mat[1][1]*mat[0][2])));
	return matrix3f_det;
}

inline void glmc_matrix3f_inverse(matrix3f dest, matrix3f src){
	float matrix3f_det_inv;
	matrix3f_det_inv = 1.0f/(glmc_matrix3f_determinant(src));
	dest[0][0] = (src[1][1]*src[2][2] - src[2][1]*src[1][2])*matrix3f_det_inv;
	dest[0][1] = -1.0f*(src[0][1]*src[2][2] - src[2][1]*src[0][2])*matrix3f_det_inv;
	dest[0][2] = (src[0][1]*src[1][2] - src[1][1]*src[0][2])*matrix3f_det_inv;
	dest[1][0] = -1.0f*(src[1][0]*src[2][2] - src[2][0]*src[1][2])*matrix3f_det_inv;
	dest[1][1] = (src[0][0]*src[2][2] - src[2][0]*src[0][2])*matrix3f_det_inv;
	dest[1][2] = -1.0f*(src[0][0]*src[1][2] - src[1][0]*src[0][2])*matrix3f_det_inv;
	dest[2][0] = (src[1][0]*src[2][1] - src[2][0]*src[1][1])*matrix3f_det_inv;
	dest[2][1] = -1.0f*(src[0][0]*src[2][1] - src[2][0]*src[0][1])*matrix3f_det_inv;
	dest[2][2] = (src[0][0]*src[1][1] - src[1][0]*src[0][1])*matrix3f_det_inv;	
}

inline void glmc_matrix3f_normlize(matrix3f dest, matrix3f src){
	float matrix3f_det_inv;
	matrix3f_det_inv = 1.0f/(glmc_matrix3f_determinant(src));
	dest[0][0] = src[0][0]*matrix3f_det_inv;
	dest[0][1] = src[0][1]*matrix3f_det_inv;
	dest[0][2] = src[0][2]*matrix3f_det_inv;
	dest[1][0] = src[1][0]*matrix3f_det_inv;
	dest[1][1] = src[1][1]*matrix3f_det_inv;
	dest[1][2] = src[1][2]*matrix3f_det_inv;
	dest[2][0] = src[2][0]*matrix3f_det_inv;
	dest[2][1] = src[2][1]*matrix3f_det_inv;
	dest[2][2] = src[2][2]*matrix3f_det_inv;
}

inline void glmc_matrix3f_normlize_dest(matrix3f src_dest){
	float matrix3f_det_inv;
	matrix3f_det_inv = 1.0f/(glmc_matrix3f_determinant(src_dest));
	src_dest[0][0] = src_dest[0][0]*matrix3f_det_inv;
	src_dest[0][1] = src_dest[0][1]*matrix3f_det_inv;
	src_dest[0][2] = src_dest[0][2]*matrix3f_det_inv;
	src_dest[1][0] = src_dest[1][0]*matrix3f_det_inv;
	src_dest[1][1] = src_dest[1][1]*matrix3f_det_inv;
	src_dest[1][2] = src_dest[1][2]*matrix3f_det_inv;
	src_dest[2][0] = src_dest[2][0]*matrix3f_det_inv;
	src_dest[2][1] = src_dest[2][1]*matrix3f_det_inv;
	src_dest[2][2] = src_dest[2][2]*matrix3f_det_inv;
}

inline void glmc_matrix3f_add(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[0][2] = src_a[0][2] + src_b[0][2];
	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	dest[1][2] = src_a[1][2] + src_b[1][2];
	dest[2][0] = src_a[2][0] + src_b[2][0];
	dest[2][1] = src_a[2][1] + src_b[2][1];
	dest[2][2] = src_a[2][2] + src_b[2][2];
}

inline void glmc_matrix3f_add_dest(matrix3f src_dest, matrix3f src_b){
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[0][2] = src_dest[0][2] + src_b[0][2];
	src_dest[1][0] = src_dest[1][0] + src_b[1][0];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
	src_dest[1][2] = src_dest[1][2] + src_b[1][2];
	src_dest[2][0] = src_dest[2][0] + src_b[2][0];
	src_dest[2][1] = src_dest[2][1] + src_b[2][1];
	src_dest[2][2] = src_dest[2][2] + src_b[2][2];
}

inline void glmc_matrix3f_sub(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[0][2] = src_a[0][2] - src_b[0][2];
	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	dest[1][2] = src_a[1][2] - src_b[1][2];
	dest[2][0] = src_a[2][0] - src_b[2][0];
	dest[2][1] = src_a[2][1] - src_b[2][1];
	dest[2][2] = src_a[2][2] - src_b[2][2];
}

inline void glmc_matrix3f_sub_dest(matrix3f src_dest, matrix3f src_b){
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[0][2] = src_dest[0][2] - src_b[0][2];
	src_dest[1][0] = src_dest[1][0] - src_b[1][0];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
	src_dest[1][2] = src_dest[1][2] - src_b[1][2];
	src_dest[2][0] = src_dest[2][0] - src_b[2][0];
	src_dest[2][1] = src_dest[2][1] - src_b[2][1];
	src_dest[2][2] = src_dest[2][2] - src_b[2][2];
}

inline void glmc_matrix3f_mul(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2]);
	dest[0][1] = (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2]);
	dest[0][2] = (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2]);
	dest[1][0] = (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2]);
	dest[1][1] = (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2]);
	dest[1][2] = (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2]);
	dest[2][0] = (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2]);
	dest[2][1] = (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2]);
	dest[2][2] = (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2]);
}

inline void glmc_matrix3f_mul_dest(matrix3f src_dest, matrix3f src_b){
	matrix3f temp;
	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];
	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];
	src_dest[0][0] = (temp[0][0]*src_b[0][0] + temp[1][0]*src_b[0][1] + temp[2][0]*src_b[0][2]);
	src_dest[0][1] = (temp[0][1]*src_b[0][0] + temp[1][1]*src_b[0][1] + temp[2][1]*src_b[0][2]);
	src_dest[0][2] = (temp[0][2]*src_b[0][0] + temp[1][2]*src_b[0][1] + temp[2][2]*src_b[0][2]);
	src_dest[1][0] = (temp[0][0]*src_b[1][0] + temp[1][0]*src_b[1][1] + temp[2][0]*src_b[1][2]);
	src_dest[1][1] = (temp[0][1]*src_b[1][0] + temp[1][1]*src_b[1][1] + temp[2][1]*src_b[1][2]);
	src_dest[1][2] = (temp[0][2]*src_b[1][0] + temp[1][2]*src_b[1][1] + temp[2][2]*src_b[1][2]);
	src_dest[2][0] = (temp[0][0]*src_b[2][0] + temp[1][0]*src_b[2][1] + temp[2][0]*src_b[2][2]);
	src_dest[2][1] = (temp[0][1]*src_b[2][0] + temp[1][1]*src_b[2][1] + temp[2][1]*src_b[2][2]);
	src_dest[2][2] = (temp[0][2]*src_b[2][0] + temp[1][2]*src_b[2][1] + temp[2][2]*src_b[2][2]);
}

inline void glmc_matrix3f_mul_s(matrix3f dest, matrix3f src_a, float src_b){
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[0][2] = src_a[0][2] * src_b;
	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	dest[1][2] = src_a[1][2] * src_b;
	dest[2][0] = src_a[2][0] * src_b;
	dest[2][1] = src_a[2][1] * src_b;
	dest[2][2] = src_a[2][2] * src_b;
}

inline void glmc_matrix3f_div(matrix3f dest, matrix3f src_a, matrix3f src_b){
	matrix3f src_b_inv;
	glmc_matrix3f_inverse(src_b_inv, src_b);
	glmc_matrix3f_mul(dest, src_a, src_b_inv);
}

inline void glmc_matrix3f_div_dest(matrix3f src_dest, matrix3f src_b){
	matrix3f temp;
	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];
	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];
	matrix3f src_b_inv;
	glmc_matrix3f_inverse(src_b_inv, src_b);
	glmc_matrix3f_mul(src_dest, temp, src_b_inv);	
}

inline void glmc_matrix3f_div_s(matrix3f dest, matrix3f src_a, float src_b){
	float src_b_inv = 1.0f/(src_b);
	dest[0][0] = src_a[0][0] * src_b_inv;
	dest[0][1] = src_a[0][1] * src_b_inv;
	dest[0][2] = src_a[0][2] * src_b_inv;
	dest[1][0] = src_a[1][0] * src_b_inv;
	dest[1][1] = src_a[1][1] * src_b_inv;
	dest[1][2] = src_a[1][2] * src_b_inv;
	dest[2][0] = src_a[2][0] * src_b_inv;
	dest[2][1] = src_a[2][1] * src_b_inv;
	dest[2][2] = src_a[2][2] * src_b_inv;
}

inline void glmc_matrix3f_addadd(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = dest[0][0] + src_a[0][0] + src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] + src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] + src_b[0][2];
	dest[1][0] = dest[1][0] + src_a[1][0] + src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] + src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] + src_b[1][2];
	dest[2][0] = dest[2][0] + src_a[2][0] + src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] + src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] + src_b[2][2];
}

inline void glmc_matrix3f_subadd(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = dest[0][0] + src_a[0][0] - src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] - src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] - src_b[0][2];
	dest[1][0] = dest[1][0] + src_a[1][0] - src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] - src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] - src_b[1][2];
	dest[2][0] = dest[2][0] + src_a[2][0] - src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] - src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] - src_b[2][2];
}

inline void glmc_matrix3f_madd(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = dest[0][0] + (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2]);
	dest[0][1] = dest[0][1] + (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2]);
	dest[0][2] = dest[0][2] + (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2]);
	dest[1][0] = dest[1][0] + (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2]);
	dest[1][1] = dest[1][1] + (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2]);
	dest[1][2] = dest[1][2] + (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2]);
	dest[2][0] = dest[2][0] + (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2]);
	dest[2][1] = dest[2][1] + (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2]);
	dest[2][2] = dest[2][2] + (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2]);
}

inline void glmc_matrix3f_msub(matrix3f dest, matrix3f src_a, matrix3f src_b){
	dest[0][0] = dest[0][0] - (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2]);
	dest[0][1] = dest[0][1] - (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2]);
	dest[0][2] = dest[0][2] - (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2]);
	dest[1][0] = dest[1][0] - (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2]);
	dest[1][1] = dest[1][1] - (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2]);
	dest[1][2] = dest[1][2] - (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2]);
	dest[2][0] = dest[2][0] - (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2]);
	dest[2][1] = dest[2][1] - (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2]);
	dest[2][2] = dest[2][2] - (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2]);
}
