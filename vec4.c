#include "glmc.h"
//TODO: Reflection and Refraction

#define float_min 1.0e-7

inline void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c){
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_b;
	dest[3] = src_c;
}

inline void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b){
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_a[2];
	dest[3] = src_b;
}

inline void glmc_vec4f_copy(vec4f dest, vec4f src){
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
}

inline float glmc_vec4f_sqrlength(vec4f vec){
	float vec4f_sqrlength;
	vec4f_sqrlength = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2] + vec[3]*vec[3];
	return vec4f_sqrlength;
}

inline float glmc_vec4f_length(vec4f vec){
	return sqrtf(glmc_vec4f_sqrlength(vec));
}

inline int glmc_vec4f_is_normalized(vec4f src){
	if(fabs(glmc_vec4f_sqrlength(src) - 1.0f) <= float_min)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

inline void glmc_vec4f_normlize(vec4f dest, vec4f src){
	if(glmc_vec4f_is_normalized(src) == 1)
	{
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
		dest[3] = src[3];
	}
	else
	{
		float vec4f_length_inv;
		vec4f_length_inv = 1.0f/(glmc_vec4f_length(src));
		dest[0] = src[0]*vec4f_length_inv;
		dest[1] = src[1]*vec4f_length_inv;
		dest[2] = src[2]*vec4f_length_inv;
		dest[3] = src[3]*vec4f_length_inv;
	}
}

inline void glmc_vec4f_normlize_dest(vec4f src_dest){
	if(glmc_vec4f_is_normalized(src_dest) != 1)
	{
		float vec4f_length_inv;
		vec4f_length_inv = 1.0f/(glmc_vec4f_length(src_dest));
		src_dest[0] = src_dest[0]*vec4f_length_inv;
		src_dest[1] = src_dest[1]*vec4f_length_inv;
		src_dest[2] = src_dest[2]*vec4f_length_inv;
		src_dest[3] = src_dest[3]*vec4f_length_inv;
	}
}

inline void glmc_vec4f_add(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = src_a[0] + src_b[0];
	dest[1] = src_a[1] + src_b[1];
	dest[2] = src_a[2] + src_b[2];
	dest[3] = src_a[3] + src_b[3];
}

inline void glmc_vec4f_add_dest(vec4f src_dest, vec4f src_b){
	src_dest[0] = src_dest[0] + src_b[0];
	src_dest[1] = src_dest[1] + src_b[1];
	src_dest[2] = src_dest[2] + src_b[2];
	src_dest[3] = src_dest[3] + src_b[3];
}

inline void glmc_vec4f_sub(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = src_a[0] - src_b[0];
	dest[1] = src_a[1] - src_b[1];
	dest[2] = src_a[2] - src_b[2];
	dest[3] = src_a[3] - src_b[3];
}

inline void glmc_vec4f_sub_dest(vec4f src_dest, vec4f src_b){
	src_dest[0] = src_dest[0] - src_b[0];
	src_dest[1] = src_dest[1] - src_b[1];
	src_dest[2] = src_dest[2] - src_b[2];
	src_dest[3] = src_dest[3] - src_b[3];
}

inline void glmc_vec4f_mul(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = src_a[0] * src_b[0];
	dest[1] = src_a[1] * src_b[1];
	dest[2] = src_a[2] * src_b[2];
	dest[3] = src_a[3] * src_b[3];
}

inline void glmc_vec4f_mul_dest(vec4f src_dest, vec4f src_b){
	src_dest[0] = src_dest[0] * src_b[0];
	src_dest[1] = src_dest[1] * src_b[1];
	src_dest[2] = src_dest[2] * src_b[2];
	src_dest[3] = src_dest[3] * src_b[3];
}

inline void glmc_vec4f_mul_s(vec4f dest, vec4f src_a, float src_b){
	dest[0] = src_a[0] * src_b;
	dest[1] = src_a[1] * src_b;
	dest[2] = src_a[2] * src_b;
	dest[3] = src_a[3] * src_b;
}

inline void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = src_a[0] / src_b[0];
	dest[1] = src_a[1] / src_b[1];
	dest[2] = src_a[2] / src_b[2];
	dest[3] = src_a[3] / src_b[3];
}

inline void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b){
	src_dest[0] = src_dest[0] / src_b[0];
	src_dest[1] = src_dest[1] / src_b[1];
	src_dest[2] = src_dest[2] / src_b[2];
	src_dest[3] = src_dest[3] / src_b[3];
}

inline void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b){
	dest[0] = src_a[0] / src_b;
	dest[1] = src_a[1] / src_b;
	dest[2] = src_a[2] / src_b;
	dest[3] = src_a[3] / src_b;
}

inline void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = dest[0] + src_a[0] + src_b[0];
	dest[1] = dest[1] + src_a[1] + src_b[1];
	dest[2] = dest[2] + src_a[2] + src_b[2];
	dest[3] = dest[3] + src_a[3] + src_b[3];
}

inline void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = dest[0] + src_a[0] - src_b[0];
	dest[1] = dest[1] + src_a[1] - src_b[1];
	dest[2] = dest[2] + src_a[2] - src_b[2];
	dest[3] = dest[3] + src_a[3] - src_b[3];
}

inline void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = dest[0] + (src_a[0] * src_b[0]);
	dest[1] = dest[1] + (src_a[1] * src_b[1]);
	dest[2] = dest[2] + (src_a[2] * src_b[2]);
	dest[3] = dest[3] + (src_a[3] * src_b[3]);
}

inline void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b){
	dest[0] = dest[0] - (src_a[0] * src_b[0]);
	dest[1] = dest[1] - (src_a[1] * src_b[1]);
	dest[2] = dest[2] - (src_a[2] * src_b[2]);
	dest[3] = dest[3] - (src_a[3] * src_b[3]);
}

inline float glmc_vec4f_dot(vec4f src_a, vec4f src_b){
	float vec4f_dot;
	vec4f_dot = (src_a[0]*src_b[0]) + (src_a[1]*src_b[1]) + (src_a[2]*src_b[2]) + (src_a[3]*src_b[3]);
	return vec4f_dot;
}

inline void glmc_vec4f_rotate(vec4f src_a,vec4f dest, float src_ux, float src_uy, float src_uz, float theta){
	matrix4f matrix_rotation;

	matrix_rotation[0][0] = c + src_ux*src_ux*(1-c); 
	matrix_rotation[0][1] = src_uy*src_ux*(1-c) + src_uz*s; 
	matrix_rotation[0][2] = src_uz*src_ux*(1-c) - src_uy*s; 
	matrix_rotation[0][3] = 0;
	matrix_rotation[1][0] = src_ux*src_uy*(1-c) - src_uz*s; 
	matrix_rotation[1][1] = c + src_uy*src_uy*(1-c); 
	matrix_rotation[1][2] = src_uz*src_uy*(1-c) + src_ux*(s); 
	matrix_rotation[1][3] = 0;
	matrix_rotation[2][0] = src_ux*src_uz*(1-c) + src_uy*s; 
	matrix_rotation[2][1] = src_uy*src_uz*(1-c) - src_ux*s; 
	matrix_rotation[2][2] = c + src_uz*src_uz*(1-c); 
	matrix_rotation[2][3] = 0;
	matrix_rotation[3][0] = 0;
	matrix_rotation[3][1] = 0;
	matrix_rotation[3][2] = 0;
	matrix_rotation[3][3] = 1.0f;
	glmc_matrix3f_mul_vec3f(dest, matrix_rotation, vec);	

}

inline void glmc_vec4f_reflection(vec4f dest, vec4f src, vec4f normal) { 
	glmc_vec4f_normlize_dest(normal); 
	float vec4f_dot = 2*glmc_vec4f_dot(src, normal); 
	vec4f temp; 
	glmc_vec4f_mul_s(temp, src, vec4f_dot); 
	glmc_vec4f_sub(dest, src, temp);  
} 
 
inline void glmc_vec4f_refraction(vec4f dest, vec4f src, vec4f normal, float src_nu) { 
	glmc_vec4f_normlize_dest(normal); 
	glmc_vec4f_normlize_dest(src); 
	float src_nu_inv = 1.0f/src_nu; 
	vec3f temp1, temp2, temp3, temp4, temp5, temp6; 
	glmc_vec4f_cross(temp1, src, normal); 
	glmc_vec4f_cross(temp2, normal, temp1); 
	glmc_vec4f_cross(temp3, normal, src); 
	float temp7 = sqrtf(1 - src_nu_inv*src_nu_inv*glmc_vec4f_dot(temp3, temp3)); 
	glmc_vec4f_mul_s(temp5, temp2, src_nu_inv); 
	glmc_vec4f_mul_s(temp6, normal, temp7); 
	glmc_vec4f_sub(dest, temp5, temp6); 

} 