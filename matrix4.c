#include "glmc.h"

inline void glmc_matrix4f_identity(matrix4f dest) { 

	dest[0][0] = 1.0f; 
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[0][3] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = 1.0f; 
	dest[1][2] = 0; 
	dest[1][3] = 0; 
	dest[2][0] = 0; 
	dest[2][1] = 0; 
	dest[2][2] = 1.0f; 
	dest[2][3] = 0; 
	dest[3][0] = 0; 
	dest[3][1] = 0; 
	dest[3][2] = 0; 
	dest[3][3] = 1.0f; 
} 

inline void glmc_matrix4f_scale(matrix4f dest, float src_sx, float src_sy, float src_sz) { 
	dest[0][0] = src_sx; 
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[0][3] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = src_sy; 
	dest[1][2] = 0; 
	dest[1][3] = 0; 
	dest[2][0] = 0; 
	dest[2][1] = 0; 
	dest[2][2] = src_sz; 
	dest[2][3] = 0; 
	dest[3][0] = 0; 
	dest[3][1] = 0; 
	dest[3][2] = 0; 
	dest[3][3] = 1.0f; 
} 
 
inline void glmc_matrix4f_translation(matrix4f dest, float src_t1, float src_t2, float src_t3) { 
	dest[0][0] = 1.0f;  
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[0][3] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = 1.0f; 
	dest[1][2] = 0; 
	dest[1][3] = 0; 
	dest[2][0] = 0; 
	dest[2][1] = 0; 
	dest[2][2] = 1.0f; 
	dest[2][3] = 0; 
	dest[3][0] = src_t1; 
	dest[3][1] = src_t2; 
	dest[3][2] = src_t3; 
	dest[3][3] = 1.0f; 
} 

inline void glmc_matrix4f_transpose(matrix4f dest, matrix4f src){
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[0][2] = src[2][0];
	dest[0][3] = src[3][0];
	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
	dest[1][2] = src[2][1];
	dest[1][3] = src[3][1];
	dest[2][0] = src[0][2];
	dest[2][1] = src[1][2];
	dest[2][2] = src[2][2];
	dest[2][3] = src[3][2];
	dest[3][0] = src[0][3];
	dest[3][1] = src[1][3];
	dest[3][2] = src[2][3];
	dest[3][3] = src[3][3];	
}

inline void glmc_matrix4f_transpose_dest(matrix4f src_dest){
	float temp;
	temp = src_dest[0][1];
	src_dest[0][1] = src_dest[1][0];
	src_dest[1][0] = temp;
	temp = src_dest[0][2];
	src_dest[0][2] = src_dest[2][0];
	src_dest[2][0] = temp;
	temp = src_dest[0][3];
	src_dest[0][3] = src_dest[3][0];
	src_dest[3][0] = temp;
	temp = src_dest[1][2];
	src_dest[1][2] = src_dest[2][1];
	src_dest[2][1] = temp;
	temp = src_dest[1][3];
	src_dest[1][3] = src_dest[3][1];
	src_dest[3][1] = temp;
	temp = src_dest[2][3];
	src_dest[2][3] = src_dest[3][2];
	src_dest[3][2] = temp;
}

inline float glmc_matrix4f_determinant(matrix4f mat){
	float matrix4f_det;
	matrix4f_det = + mat[0][0]*((mat[1][1]*((mat[2][2]*mat[3][3])-(mat[3][2]*mat[2][3]))) - (mat[2][1]*((mat[1][2]*mat[3][3])-(mat[3][2]*mat[1][3]))) + (mat[3][1]*((mat[1][2]*mat[2][3])-(mat[2][2]*mat[1][3]))))

				- mat[1][0]*((mat[0][1]*((mat[2][2]*mat[3][3])-(mat[3][2]*mat[2][3]))) - (mat[2][1]*((mat[0][2]*mat[3][3])-(mat[3][2]*mat[0][3]))) + (mat[3][1]*((mat[0][2]*mat[2][3])-(mat[2][2]*mat[0][3]))))

				+ mat[2][0]*((mat[0][1]*((mat[1][2]*mat[3][3])-(mat[3][2]*mat[1][3]))) - (mat[1][1]*((mat[0][2]*mat[3][3])-(mat[3][2]*mat[0][3]))) + (mat[3][1]*((mat[0][2]*mat[1][3])-(mat[1][2]*mat[0][3]))))

				- mat[3][0]*((mat[0][1]*((mat[1][2]*mat[2][3])-(mat[2][2]*mat[1][3]))) - (mat[1][1]*((mat[0][2]*mat[2][3])-(mat[2][2]*mat[0][3]))) + (mat[2][1]*((mat[0][2]*mat[1][3])-(mat[1][2]*mat[0][3]))));

	return matrix4f_det;
}

inline void glmc_matrix4f_inverse(matrix4f dest, matrix4f src){
	float matrix4f_det_inv;
	matrix4f_det_inv = 1.0f/(glmc_matrix4f_determinant(src));
	dest[0][0] = ((src[1][1]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][1]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) + (src[3][1]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))))*matrix4f_det_inv;

	dest[0][1] = -1.0f*((src[0][1]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][1]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][1]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))))*matrix4f_det_inv;

	dest[0][2] = ((src[0][1]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) - (src[1][1]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][1]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*matrix4f_det_inv;

	dest[0][3] = -1.0f*((src[0][1]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))) - (src[1][1]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))) + (src[2][1]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*matrix4f_det_inv;

	dest[1][0] = -1.0f*((src[1][0]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][0]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) + (src[3][0]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))))*matrix4f_det_inv;

	dest[1][1] = ((src[0][0]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][0]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][0]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))))*matrix4f_det_inv;

	dest[1][2] = -1.0f*((src[0][0]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) - (src[1][0]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][0]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*matrix4f_det_inv;

	dest[1][3] = ((src[0][0]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))) - (src[1][0]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))) + (src[2][0]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*matrix4f_det_inv;

	dest[2][0] = ((src[1][0]*((src[2][1]*src[3][3])-(src[3][1]*src[2][3]))) - (src[2][0]*((src[1][1]*src[3][3])-(src[3][1]*src[1][3]))) + (src[3][0]*((src[1][1]*src[2][3])-(src[2][1]*src[1][3]))))*matrix4f_det_inv;

	dest[2][1] = -1.0f*((src[0][0]*((src[2][1]*src[3][3])-(src[3][1]*src[2][3]))) - (src[2][0]*((src[0][1]*src[3][3])-(src[3][1]*src[0][3]))) + (src[3][0]*((src[0][1]*src[2][3])-(src[2][1]*src[0][3]))))*matrix4f_det_inv;

	dest[2][2] = ((src[0][0]*((src[1][1]*src[3][3])-(src[3][1]*src[1][3]))) - (src[1][0]*((src[0][1]*src[3][3])-(src[3][1]*src[0][3]))) + (src[3][0]*((src[0][1]*src[1][3])-(src[1][1]*src[0][3]))))*matrix4f_det_inv;

	dest[2][3] = -1.0f*((src[0][0]*((src[1][1]*src[2][3])-(src[2][1]*src[1][3]))) - (src[1][0]*((src[0][1]*src[2][3])-(src[2][1]*src[0][3]))) + (src[2][0]*((src[0][1]*src[1][3])-(src[1][1]*src[0][3]))))*matrix4f_det_inv;

	dest[3][0] = -1.0f*((src[1][0]*((src[2][1]*src[3][2])-(src[3][1]*src[2][2]))) - (src[2][0]*((src[1][1]*src[3][2])-(src[3][1]*src[1][2]))) + (src[3][0]*((src[1][1]*src[2][2])-(src[2][1]*src[1][2]))))*matrix4f_det_inv;

	dest[3][1] = ((src[0][0]*((src[2][1]*src[3][2])-(src[3][1]*src[2][2]))) - (src[2][0]*((src[0][1]*src[3][2])-(src[3][1]*src[0][2]))) + (src[3][0]*((src[0][1]*src[2][2])-(src[2][1]*src[0][2]))))*matrix4f_det_inv;

	dest[3][2] = -1.0f*((src[0][0]*((src[1][1]*src[3][2])-(src[3][1]*src[1][2]))) - (src[1][0]*((src[0][1]*src[3][2])-(src[3][1]*src[0][2]))) + (src[3][0]*((src[0][1]*src[1][2])-(src[1][1]*src[0][2]))))*matrix4f_det_inv;

	dest[3][3] = ((src[0][0]*((src[1][1]*src[2][2])-(src[2][1]*src[1][2]))) - (src[1][0]*((src[0][1]*src[2][2])-(src[2][1]*src[0][2]))) + (src[2][0]*((src[0][1]*src[1][2])-(src[1][1]*src[0][2]))))*matrix4f_det_inv;

}

inline void glmc_matrix4f_normlize(matrix4f dest, matrix4f src){
	float matrix4f_det_inv;
	matrix4f_det_inv = 1.0f/(glmc_matrix4f_determinant(src));
	dest[0][0] = src[0][0] * matrix4f_det_inv;
	dest[0][1] = src[0][1] * matrix4f_det_inv;
	dest[0][2] = src[0][2] * matrix4f_det_inv;
	dest[0][3] = src[0][3] * matrix4f_det_inv;
	dest[1][0] = src[1][0] * matrix4f_det_inv;
	dest[1][1] = src[1][1] * matrix4f_det_inv;
	dest[1][2] = src[1][2] * matrix4f_det_inv;
	dest[1][3] = src[1][3] * matrix4f_det_inv;
	dest[2][0] = src[2][0] * matrix4f_det_inv;
	dest[2][1] = src[2][1] * matrix4f_det_inv;
	dest[2][2] = src[2][2] * matrix4f_det_inv;
	dest[2][3] = src[2][3] * matrix4f_det_inv;
	dest[3][0] = src[3][0] * matrix4f_det_inv;
	dest[3][1] = src[3][1] * matrix4f_det_inv;
	dest[3][2] = src[3][2] * matrix4f_det_inv;
	dest[3][3] = src[3][3] * matrix4f_det_inv;
}

inline void glmc_matrix4f_normlize_dest(matrix4f src_dest){
	float matrix4f_det_inv;
	matrix4f_det_inv = 1.0f/(glmc_matrix4f_determinant(src_dest));
	src_dest[0][0] = src_dest[0][0] * matrix4f_det_inv;
	src_dest[0][1] = src_dest[0][1] * matrix4f_det_inv;
	src_dest[0][2] = src_dest[0][2] * matrix4f_det_inv;
	src_dest[0][3] = src_dest[0][3] * matrix4f_det_inv;
	src_dest[1][0] = src_dest[1][0] * matrix4f_det_inv;
	src_dest[1][1] = src_dest[1][1] * matrix4f_det_inv;
	src_dest[1][2] = src_dest[1][2] * matrix4f_det_inv;
	src_dest[1][3] = src_dest[1][3] * matrix4f_det_inv;
	src_dest[2][0] = src_dest[2][0] * matrix4f_det_inv;
	src_dest[2][1] = src_dest[2][1] * matrix4f_det_inv;
	src_dest[2][2] = src_dest[2][2] * matrix4f_det_inv;
	src_dest[2][3] = src_dest[2][3] * matrix4f_det_inv;
	src_dest[3][0] = src_dest[3][0] * matrix4f_det_inv;
	src_dest[3][1] = src_dest[3][1] * matrix4f_det_inv;
	src_dest[3][2] = src_dest[3][2] * matrix4f_det_inv;
	src_dest[3][3] = src_dest[3][3] * matrix4f_det_inv;
}

inline void glmc_matrix4f_add(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[0][2] = src_a[0][2] + src_b[0][2];
	dest[0][3] = src_a[0][3] + src_b[0][3];
	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	dest[1][2] = src_a[1][2] + src_b[1][2];
	dest[1][3] = src_a[1][3] + src_b[1][3];
	dest[2][0] = src_a[2][0] + src_b[2][0];
	dest[2][1] = src_a[2][1] + src_b[2][1];
	dest[2][2] = src_a[2][2] + src_b[2][2];
	dest[2][3] = src_a[2][3] + src_b[2][3];	
	dest[3][0] = src_a[3][0] + src_b[3][0];
	dest[3][1] = src_a[3][1] + src_b[3][1];
	dest[3][2] = src_a[3][2] + src_b[3][2];
	dest[3][3] = src_a[3][3] + src_b[3][3];
}

inline void glmc_matrix4f_add_dest(matrix4f src_dest, matrix4f src_b){
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[0][2] = src_dest[0][2] + src_b[0][2];
	src_dest[0][3] = src_dest[0][3] + src_b[0][3];
	src_dest[1][0] = src_dest[1][0] + src_b[1][0];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
	src_dest[1][2] = src_dest[1][2] + src_b[1][2];
	src_dest[1][3] = src_dest[1][3] + src_b[1][3];
	src_dest[2][0] = src_dest[2][0] + src_b[2][0];
	src_dest[2][1] = src_dest[2][1] + src_b[2][1];
	src_dest[2][2] = src_dest[2][2] + src_b[2][2];
	src_dest[2][3] = src_dest[2][3] + src_b[2][3];	
	src_dest[3][0] = src_dest[3][0] + src_b[3][0];
	src_dest[3][1] = src_dest[3][1] + src_b[3][1];
	src_dest[3][2] = src_dest[3][2] + src_b[3][2];
	src_dest[3][3] = src_dest[3][3] + src_b[3][3];	
}

inline void glmc_matrix4f_sub(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[0][2] = src_a[0][2] - src_b[0][2];
	dest[0][3] = src_a[0][3] - src_b[0][3];
	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	dest[1][2] = src_a[1][2] - src_b[1][2];
	dest[1][3] = src_a[1][3] - src_b[1][3];
	dest[2][0] = src_a[2][0] - src_b[2][0];
	dest[2][1] = src_a[2][1] - src_b[2][1];
	dest[2][2] = src_a[2][2] - src_b[2][2];
	dest[2][3] = src_a[2][3] - src_b[2][3];
	dest[3][0] = src_a[3][0] - src_b[3][0];
	dest[3][1] = src_a[3][1] - src_b[3][1];
	dest[3][2] = src_a[3][2] - src_b[3][2];
	dest[3][3] = src_a[3][3] - src_b[3][3];
}

inline void glmc_matrix4f_sub_dest(matrix4f src_dest, matrix4f src_b){
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[0][2] = src_dest[0][2] - src_b[0][2];
	src_dest[0][3] = src_dest[0][3] - src_b[0][3];
	src_dest[1][0] = src_dest[1][0] - src_b[1][0];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
	src_dest[1][2] = src_dest[1][2] - src_b[1][2];
	src_dest[1][3] = src_dest[1][3] - src_b[1][3];
	src_dest[2][0] = src_dest[2][0] - src_b[2][0];
	src_dest[2][1] = src_dest[2][1] - src_b[2][1];
	src_dest[2][2] = src_dest[2][2] - src_b[2][2];
	src_dest[2][3] = src_dest[2][3] - src_b[2][3];
	src_dest[3][0] = src_dest[3][0] - src_b[3][0];
	src_dest[3][1] = src_dest[3][1] - src_b[3][1];
	src_dest[3][2] = src_dest[3][2] - src_b[3][2];
	src_dest[3][3] = src_dest[3][3] - src_b[3][3];		
}

inline void glmc_matrix4f_mul(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3]);
	dest[0][1] = (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3]);
	dest[0][2] = (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3]);
	dest[0][3] = (src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3]);
	dest[1][0] = (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3]);
	dest[1][1] = (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3]);
	dest[1][2] = (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3]);
	dest[1][3] = (src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3]);
	dest[2][0] = (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3]);
	dest[2][1] = (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3]);
	dest[2][2] = (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3]);
	dest[2][3] = (src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3]);
	dest[3][0] = (src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3]);
	dest[3][1] = (src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3]);
	dest[3][2] = (src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3]);
	dest[3][3] = (src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3]);
}

inline void glmc_matrix4f_mul_dest(matrix4f src_dest, matrix4f src_b){
	matrix4f temp;
	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];
	temp[0][3] = src_dest[0][3];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];
	temp[1][3] = src_dest[1][3];
	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];
	temp[2][3] = src_dest[2][3];
	temp[3][0] = src_dest[3][0];
	temp[3][1] = src_dest[3][1];
	temp[3][2] = src_dest[3][2];
	temp[3][3] = src_dest[3][3];
	src_dest[0][0] = (temp[0][0]*src_b[0][0] + temp[1][0]*src_b[0][1] + temp[2][0]*src_b[0][2] + temp[3][0]*src_b[0][3]);
	src_dest[0][1] = (temp[0][1]*src_b[0][0] + temp[1][1]*src_b[0][1] + temp[2][1]*src_b[0][2] + temp[3][1]*src_b[0][3]);
	src_dest[0][2] = (temp[0][2]*src_b[0][0] + temp[1][2]*src_b[0][1] + temp[2][2]*src_b[0][2] + temp[3][2]*src_b[0][3]);
	src_dest[0][3] = (temp[0][3]*src_b[0][0] + temp[1][3]*src_b[0][1] + temp[2][3]*src_b[0][2] + temp[3][3]*src_b[0][3]);
	src_dest[1][0] = (temp[0][0]*src_b[1][0] + temp[1][0]*src_b[1][1] + temp[2][0]*src_b[1][2] + temp[3][0]*src_b[1][3]);
	src_dest[1][1] = (temp[0][1]*src_b[1][0] + temp[1][1]*src_b[1][1] + temp[2][1]*src_b[1][2] + temp[3][1]*src_b[1][3]);
	src_dest[1][2] = (temp[0][2]*src_b[1][0] + temp[1][2]*src_b[1][1] + temp[2][2]*src_b[1][2] + temp[3][2]*src_b[1][3]);
	src_dest[1][3] = (temp[0][3]*src_b[1][0] + temp[1][3]*src_b[1][1] + temp[2][3]*src_b[1][2] + temp[3][3]*src_b[1][3]);
	src_dest[2][0] = (temp[0][0]*src_b[2][0] + temp[1][0]*src_b[2][1] + temp[2][0]*src_b[2][2] + temp[3][0]*src_b[2][3]);
	src_dest[2][1] = (temp[0][1]*src_b[2][0] + temp[1][1]*src_b[2][1] + temp[2][1]*src_b[2][2] + temp[3][1]*src_b[2][3]);
	src_dest[2][2] = (temp[0][2]*src_b[2][0] + temp[1][2]*src_b[2][1] + temp[2][2]*src_b[2][2] + temp[3][2]*src_b[2][3]);
	src_dest[2][3] = (temp[0][3]*src_b[2][0] + temp[1][3]*src_b[2][1] + temp[2][3]*src_b[2][2] + temp[3][3]*src_b[2][3]);
	src_dest[3][0] = (temp[0][0]*src_b[3][0] + temp[1][0]*src_b[3][1] + temp[2][0]*src_b[3][2] + temp[3][0]*src_b[3][3]);
	src_dest[3][1] = (temp[0][1]*src_b[3][0] + temp[1][1]*src_b[3][1] + temp[2][1]*src_b[3][2] + temp[3][1]*src_b[3][3]);
	src_dest[3][2] = (temp[0][2]*src_b[3][0] + temp[1][2]*src_b[3][1] + temp[2][2]*src_b[3][2] + temp[3][2]*src_b[3][3]);
	src_dest[3][3] = (temp[0][3]*src_b[3][0] + temp[1][3]*src_b[3][1] + temp[2][3]*src_b[3][2] + temp[3][3]*src_b[3][3]);
}

inline void glmc_matrix4f_mul_s(matrix4f dest, matrix4f src_a, float src_b){
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[0][2] = src_a[0][2] * src_b;
	dest[0][3] = src_a[0][3] * src_b;
	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	dest[1][2] = src_a[1][2] * src_b;
	dest[1][3] = src_a[1][3] * src_b;
	dest[2][0] = src_a[2][0] * src_b;
	dest[2][1] = src_a[2][1] * src_b;
	dest[2][2] = src_a[2][2] * src_b;
	dest[2][3] = src_a[2][3] * src_b;
	dest[3][0] = src_a[3][0] * src_b;
	dest[3][1] = src_a[3][1] * src_b;
	dest[3][2] = src_a[3][2] * src_b;
	dest[3][3] = src_a[3][3] * src_b;
}

inline void glmc_matrix4f_div(matrix4f dest, matrix4f src_a, matrix4f src_b){
	matrix4f src_b_inv;
	glmc_matrix4f_inverse(src_b_inv, src_b);
	glmc_matrix4f_mul(dest, src_a, src_b_inv);
}

inline void glmc_matrix4f_div_dest(matrix4f src_dest, matrix4f src_b){
	matrix4f temp;
	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];
	temp[0][3] = src_dest[0][3];
	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];
	temp[1][3] = src_dest[1][3];
	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];
	temp[2][3] = src_dest[2][3];
	temp[3][0] = src_dest[3][0];
	temp[3][1] = src_dest[3][1];
	temp[3][2] = src_dest[3][2];
	temp[3][3] = src_dest[3][3];
	matrix4f src_b_inv;
	glmc_matrix4f_inverse(src_b_inv, src_b);
	glmc_matrix4f_mul(src_dest, temp, src_b_inv);
}

inline void glmc_matrix4f_div_s(matrix4f dest, matrix4f src_a, float src_b){
	float src_b_inv = 1.0f/(src_b);
	dest[0][0] = src_a[0][0] * src_b_inv;
	dest[0][1] = src_a[0][1] * src_b_inv;
	dest[0][2] = src_a[0][2] * src_b_inv;
	dest[0][3] = src_a[0][3] * src_b_inv;
	dest[1][0] = src_a[1][0] * src_b_inv;
	dest[1][1] = src_a[1][1] * src_b_inv;
	dest[1][2] = src_a[1][2] * src_b_inv;
	dest[1][3] = src_a[1][3] * src_b_inv;
	dest[2][0] = src_a[2][0] * src_b_inv;
	dest[2][1] = src_a[2][1] * src_b_inv;
	dest[2][2] = src_a[2][2] * src_b_inv;
	dest[2][3] = src_a[2][3] * src_b_inv;
	dest[3][0] = src_a[3][0] * src_b_inv;
	dest[3][1] = src_a[3][1] * src_b_inv;
	dest[3][2] = src_a[3][2] * src_b_inv;
	dest[3][3] = src_a[3][3] * src_b_inv;
}

inline void glmc_matrix4f_addadd(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = dest[0][0] + src_a[0][0] + src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] + src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] + src_b[0][2];
	dest[0][3] = dest[0][3] + src_a[0][3] + src_b[0][3];
	dest[1][0] = dest[1][0] + src_a[1][0] + src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] + src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] + src_b[1][2];
	dest[1][3] = dest[1][3] + src_a[1][3] + src_b[1][3];
	dest[2][0] = dest[2][0] + src_a[2][0] + src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] + src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] + src_b[2][2];
	dest[2][3] = dest[2][3] + src_a[2][3] + src_b[2][3];	
	dest[3][0] = dest[3][0] + src_a[3][0] + src_b[3][0];
	dest[3][1] = dest[3][1] + src_a[3][1] + src_b[3][1];
	dest[3][2] = dest[3][2] + src_a[3][2] + src_b[3][2];
	dest[3][3] = dest[3][3] + src_a[3][3] + src_b[3][3];	
}

inline void glmc_matrix4f_subadd(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = dest[0][0] + src_a[0][0] - src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] - src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] - src_b[0][2];
	dest[0][3] = dest[0][3] + src_a[0][3] - src_b[0][3];
	dest[1][0] = dest[1][0] + src_a[1][0] - src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] - src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] - src_b[1][2];
	dest[1][3] = dest[1][3] + src_a[1][3] - src_b[1][3];
	dest[2][0] = dest[2][0] + src_a[2][0] - src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] - src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] - src_b[2][2];
	dest[2][3] = dest[2][3] + src_a[2][3] - src_b[2][3];	
	dest[3][0] = dest[3][0] + src_a[3][0] - src_b[3][0];
	dest[3][1] = dest[3][1] + src_a[3][1] - src_b[3][1];
	dest[3][2] = dest[3][2] + src_a[3][2] - src_b[3][2];
	dest[3][3] = dest[3][3] + src_a[3][3] - src_b[3][3];	
}

inline void glmc_matrix4f_madd(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = dest[0][0] + (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3]);
	dest[0][1] = dest[0][1] + (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3]);
	dest[0][2] = dest[0][2] + (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3]);
	dest[0][3] = dest[0][3] + (src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3]);
	dest[1][0] = dest[1][0] + (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3]);
	dest[1][1] = dest[1][1] + (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3]);
	dest[1][2] = dest[1][2] + (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3]);
	dest[1][3] = dest[1][3] + (src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3]);
	dest[2][0] = dest[2][0] + (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3]);
	dest[2][1] = dest[2][1] + (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3]);
	dest[2][2] = dest[2][2] + (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3]);
	dest[2][3] = dest[2][3] + (src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3]);
	dest[3][0] = dest[3][0] + (src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3]);
	dest[3][1] = dest[3][1] + (src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3]);
	dest[3][2] = dest[3][2] + (src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3]);
	dest[3][3] = dest[3][3] + (src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3]);
}

inline void glmc_matrix4f_msub(matrix4f dest, matrix4f src_a, matrix4f src_b){
	dest[0][0] = dest[0][0] - (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3]);
	dest[0][1] = dest[0][1] - (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3]);
	dest[0][2] = dest[0][2] - (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3]);
	dest[0][3] = dest[0][3] - (src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3]);
	dest[1][0] = dest[1][0] - (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3]);
	dest[1][1] = dest[1][1] - (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3]);
	dest[1][2] = dest[1][2] - (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3]);
	dest[1][3] = dest[1][3] - (src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3]);
	dest[2][0] = dest[2][0] - (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3]);
	dest[2][1] = dest[2][1] - (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3]);
	dest[2][2] = dest[2][2] - (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3]);
	dest[2][3] = dest[2][3] - (src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3]);
	dest[3][0] = dest[3][0] - (src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3]);
	dest[3][1] = dest[3][1] - (src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3]);
	dest[3][2] = dest[3][2] - (src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3]);
	dest[3][3] = dest[3][3] - (src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3]);	
}

inline void glmc_matrix4f_perspective_proj(matrix4f dest, float src_fovy, float src_aspect, float src_zNear, float src_zFar) { 
	float tanHalfFovy = tan(src_fovy/2); 
	dest[0][0] = 1.0f/(src_aspect*tanHalfFovy); 
	dest[0][1] = 0; 
	dest[0][2] = 0; 
	dest[0][3] = 0; 
	dest[1][0] = 0; 
	dest[1][1] = 1.0f/tanHalfFovy; 
	dest[1][2] = 0; 
	dest[1][3] = 0; 
	dest[2][0] = 0; 
	dest[2][1] = 0; 
	dest[2][2] = src_zFar/(src_zFar - src_zNear); 
	dest[2][3] = 1.0f; 
	dest[3][0] = 0; 
	dest[3][1] = 0; 
	dest[3][2] = 0; 
	dest[3][3] = -1.0f*(src_zFar*src_zNear)/(src_zFar - src_zNear); 
} 
 
inline void glmc_matrix4f_ortho_proj(matrix4f dest, float src_left, float src_right, float src_bottom, float src_top) { 
	dest[0][0] = 2.0f/(src_right - src_left);  
	dest[0][1] = 1.0f;
	dest[0][2] = 1.0f; 
	dest[0][3] = 1.0f;
	dest[1][0] = 1.0f; 
	dest[1][1] = 2.0f/(src_top - src_bottom); 
	dest[1][2] = 1.0f; 
	dest[1][3] = 1.0f;
	dest[2][0] = 1.0f; 
	dest[2][1] = 1.0f; 
	dest[2][2] = 1.0f; 
	dest[2][3] = 1.0f; 
	dest[3][0] = -1.0f*(src_right + src_left)/(src_right - src_left); 
	dest[3][1] = -1.0f*(src_top + src_bottom)/(src_top - src_bottom); 
	dest[3][2] = 1.0f; 
	dest[3][3] = 1.0f; 
}

inline void glmc_matrix4f_default_normalize(matrix4f dest) { 
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%f",&dest[i][j]);
		}
	}
	#ifdef NORMALISE  
		glmc_matrix4f_normlize_dest(dest); 
	#endif  
} 

 
inline void glmc_convert_4f_to_oneD(oneD_to_4f dest, matrix4f src) { 
	dest[0] = src[0][0]; 
	dest[1] = src[1][0]; 
	dest[2] = src[2][0]; 
	dest[3] = src[3][0]; 
	dest[4] = src[0][1]; 
	dest[5] = src[1][1]; 
	dest[6] = src[2][1]; 
	dest[7] = src[3][1]; 
	dest[8] = src[0][2]; 
	dest[9] = src[1][2]; 
	dest[10] = src[2][2]; 
	dest[11] = src[3][2]; 
	dest[12] = src[0][3]; 
	dest[13] = src[1][3]; 
	dest[14] = src[2][3]; 
	dest[15] = src[3][3]; 
} 

inline void glmc_convert_oneD_to_4f(matrix4f dest, oneD_to_4f src) { 
	dest[0][0] = src[0]; 
	dest[1][0] = src[1]; 
	dest[2][0] = src[2]; 
	dest[3][0] = src[3]; 
	dest[0][1] = src[4]; 
	dest[1][1] = src[5]; 
	dest[2][1] = src[6]; 
 	dest[3][1] = src[7]; 
	dest[0][2] = src[8]; 
	dest[1][2] = src[9]; 
	dest[2][2] = src[10]; 
	dest[3][2] = src[11]; 
	dest[0][3] = src[12]; 
	dest[1][3] = src[13]; 
	dest[2][3] = src[14]; 
	dest[3][3] = src[15];
} 
