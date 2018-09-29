#include "glmc.h"

inline void glmc_matrix2f_identity(matrix2f dest) { 

	dest[0][0] = 1.0f; 
	dest[0][1] = 0;  
	dest[1][0] = 0; 
	dest[1][1] = 1.0f; 
} 

inline void glmc_matrix2f_scale(matrix2f dest, float src_sx) { 
	dest[0][0] = src_sx; 
	dest[0][1] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = 1.0f; 
} 

inline void glmc_matrix2f_translation(matrix2f dest, float src_t1) { 
	dest[0][0] = 1.0f;
	dest[0][1] = 0; 
	dest[1][0] = src_t1; 
	dest[1][1] = 1.0f; 
} 

inline void glmc_matrix2f_rotation(matrix2f dest, float theta)  { 
	float c = cos(theta); 
	float s = sin(theta);  
	dest[0][0] = c;  
	dest[0][1] = s;  
	dest[1][0] = -1.0f*s; 
	dest[1][1] = c; 
}

inline void glmc_matrix2f_transpose(matrix2f dest, matrix2f src){
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
}

inline void glmc_matrix2f_transpose_dest(matrix2f src_dest){
	float temp;
	temp = src_dest[0][1];
	src_dest[0][1] = src_dest[1][0];
	src_dest[1][0] = temp;
}

inline float glmc_matrix2f_determinant(matrix2f mat){
	float matrix2f_det;
	matrix2f_det = (mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1]);
	return matrix2f_det;
}

inline void glmc_matrix2f_inverse(matrix2f dest, matrix2f src){
	float matrix2f_det_inv;
	matrix2f_det_inv = 1.0f/(glmc_matrix2f_determinant(src));
	dest[0][0] = src[1][1]*matrix2f_det_inv;
	dest[0][1] = -1.0f*src[0][1]*matrix2f_det_inv;
	dest[1][0] = -1.0f*src[1][0]*matrix2f_det_inv;
	dest[1][1] = src[0][0]*matrix2f_det_inv;;	
}

inline void glmc_matrix2f_normlize(matrix2f dest, matrix2f src){
	float matrix2f_det_inv;
	matrix2f_det_inv = 1.0f/(glmc_matrix2f_determinant(src));
	dest[0][0] = src[0][0]*matrix2f_det_inv;
	dest[0][1] = src[0][1]*matrix2f_det_inv;
	dest[1][0] = src[1][0]*matrix2f_det_inv;
	dest[1][1] = src[1][1]*matrix2f_det_inv;
}

inline void glmc_matrix2f_normlize_dest(matrix2f src_dest){
	float matrix2f_det_inv;
	matrix2f_det_inv = 1.0f/(glmc_matrix2f_determinant(src_dest));
	src_dest[0][0] = src_dest[0][0]*matrix2f_det_inv;
	src_dest[0][1] = src_dest[0][1]*matrix2f_det_inv;
	src_dest[1][0] = src_dest[1][0]*matrix2f_det_inv;
	src_dest[1][1] = src_dest[1][1]*matrix2f_det_inv;
}

inline void glmc_matrix2f_add(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
}

inline void glmc_matrix2f_add_dest(matrix2f src_dest, matrix2f src_b){
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[1][0] = src_dest[1][0] + src_b[1][0];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
}

inline void glmc_matrix2f_sub(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
}

inline void glmc_matrix2f_sub_dest(matrix2f src_dest, matrix2f src_b){
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[1][0] = src_dest[1][0] - src_b[1][0];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
}

inline void glmc_matrix2f_mul(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1]);
	dest[0][1] = (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1]);
	dest[1][0] = (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1]);
	dest[1][1] = (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1]);
}

inline void glmc_matrix2f_mul_dest(matrix2f src_dest, matrix2f src_b){
	matrix2f temp;
	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	src_dest[0][0] = (temp[0][0]*src_b[0][0] + temp[1][0]*src_b[0][1]);
	src_dest[0][1] = (temp[0][1]*src_b[0][0] + temp[1][1]*src_b[0][1]);
	src_dest[1][0] = (temp[0][0]*src_b[1][0] + temp[1][0]*src_b[1][1]);
	src_dest[1][1] = (temp[0][1]*src_b[1][0] + temp[1][1]*src_b[1][1]);
}

inline void glmc_matrix2f_mul_s(matrix2f dest, matrix2f src_a, float src_b){
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
}

inline void glmc_matrix2f_div(matrix2f dest, matrix2f src_a, matrix2f src_b){
	matrix2f src_b_inv;
	glmc_matrix2f_inverse(src_b_inv, src_b);
	glmc_matrix2f_mul(dest, src_a, src_b_inv);
}

inline void glmc_matrix2f_div_dest(matrix2f src_dest, matrix2f src_b){
	matrix2f temp;
	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	matrix2f src_b_inv;
	glmc_matrix2f_inverse(src_b_inv, src_b);
	glmc_matrix2f_mul(src_dest, temp, src_b_inv);	
}

inline void glmc_matrix2f_div_s(matrix2f dest, matrix2f src_a, float src_b){
	float src_b_inv = 1.0f/(src_b);
	dest[0][0] = src_a[0][0] * src_b_inv;
	dest[0][1] = src_a[0][1] * src_b_inv;
	dest[1][0] = src_a[1][0] * src_b_inv;
	dest[1][1] = src_a[1][1] * src_b_inv;
}

inline void glmc_matrix2f_addadd(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = dest[0][0] + src_a[0][0] + src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] + src_b[0][1];
	dest[1][0] = dest[1][0] + src_a[1][0] + src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] + src_b[1][1];
}

inline void glmc_matrix2f_subadd(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = dest[0][0] + src_a[0][0] - src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] - src_b[0][1];
	dest[1][0] = dest[1][0] + src_a[1][0] - src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] - src_b[1][1];
}

inline void glmc_matrix2f_madd(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = dest[0][0] + (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1]);
	dest[0][1] = dest[0][1] + (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1]);
	dest[1][0] = dest[1][0] + (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1]);
	dest[1][1] = dest[1][1] + (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1]);
}

inline void glmc_matrix2f_msub(matrix2f dest, matrix2f src_a, matrix2f src_b){
	dest[0][0] = dest[0][0] - (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1]);
	dest[0][1] = dest[0][1] - (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1]);
	dest[1][0] = dest[1][0] - (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1]);
	dest[1][1] = dest[1][1] - (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1]);
}
