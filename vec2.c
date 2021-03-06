#include "glmc.h"

#define float_min 1.0e-7

inline void glmc_vec2f_from_3f(vec2f dest, vec3f src){
	dest[0] = src[0];
	dest[1] = src[1];
}

inline void glmc_vec2f_from_4f(vec2f dest, vec4f src){
	dest[0] = src[0];
	dest[1] = src[1];
}

inline void glmc_vec2f_copy(vec2f dest, vec2f src){
	dest[0] = src[0];
	dest[1] = src[1];
}

inline float glmc_vec2f_sqrlength(vec2f vec){
	float vec2f_sqrlength;
	vec2f_sqrlength = vec[0]*vec[0] + vec[1]*vec[1];
	return vec2f_sqrlength;
}

inline float glmc_vec2f_length(vec2f vec){
	return sqrtf(glmc_vec2f_sqrlength(vec));
}

inline int glmc_vec2f_is_normalized(vec2f src){
	if(fabs(glmc_vec2f_sqrlength(src) - 1.0f) <= float_min){
		return 1;
	}
	else{
		return 0;
	}
}

inline void glmc_vec2f_normlize(vec2f dest, vec2f src){
	if(glmc_vec2f_is_normalized(src) == 1){
		dest[0] = src[0];
		dest[1] = src[1];
	}
	else{
		float vec2f_length_inv;
		vec2f_length_inv = 1.0f/(glmc_vec2f_length(src));
		dest[0] = src[0]*vec2f_length_inv;
		dest[1] = src[1]*vec2f_length_inv;
	}
}

inline void glmc_vec2f_normlize_dest(vec2f src_dest){
	if(glmc_vec2f_is_normalized(src_dest) != 1){
		float vec2f_length_inv;
		vec2f_length_inv = 1.0f/(glmc_vec2f_length(src_dest));
		src_dest[0] = src_dest[0]*vec2f_length_inv;
		src_dest[1] = src_dest[1]*vec2f_length_inv;
	}
}

inline void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = src_a[0] + src_b[0];
	dest[1] = src_a[1] + src_b[1];
}

inline void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b){
	src_dest[0] = src_dest[0] + src_b[0];
	src_dest[1] = src_dest[1] + src_b[1];
}

inline void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = src_a[0] - src_b[0];
	dest[1] = src_a[1] - src_b[1];
}

inline void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b){
	src_dest[0] = src_dest[0] - src_b[0];
	src_dest[1] = src_dest[1] - src_b[1];
}

inline void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = src_a[0] * src_b[0];
	dest[1] = src_a[1] * src_b[1];
}

inline void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b){
	src_dest[0] = src_dest[0] * src_b[0];
	src_dest[1] = src_dest[1] * src_b[1];
}

inline void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b){
	dest[0] = src_a[0] * src_b;
	dest[1] = src_a[1] * src_b;
}

inline void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = src_a[0] / src_b[0];
	dest[1] = src_a[1] / src_b[1];
}

inline void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b){
	src_dest[0] = src_dest[0] / src_b[0];
	src_dest[1] = src_dest[1] / src_b[1];
}

inline void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b){
	dest[0] = src_a[0] / src_b;
	dest[1] = src_a[1] / src_b;
}

inline void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = dest[0] + src_a[0] + src_b[0];
	dest[1] = dest[1] + src_a[1] + src_b[1];
}

inline void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = dest[0] + src_a[0] - src_b[0];
	dest[1] = dest[1] + src_a[1] - src_b[1];
}

inline void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = dest[0] + (src_a[0] * src_b[0]);
	dest[1] = dest[1] + (src_a[1] * src_b[1]);
}

inline void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b){
	dest[0] = dest[0] - (src_a[0] * src_b[0]);
	dest[1] = dest[1] - (src_a[1] * src_b[1]);
}

inline float glmc_vec2f_dot(vec2f src_a, vec2f src_b){
	float vec2f_dot;
	vec2f_dot = (src_a[0]*src_b[0]) + (src_a[1]*src_b[1]);
	return vec2f_dot;
}