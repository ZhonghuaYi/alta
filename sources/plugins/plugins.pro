TEMPLATE = subdirs

SUBDIRS  = \
	rational_fitter_cgal						\
	rational_fitter_quadprog					\
	rational_fitter_parallel					\
	rational_fitter_eigen						\
	rational_fitter_leastsquare					\
	rational_fitter_matlab						\
	rational_fitter_dca						\
	rational_fitter_parsec_one					\
	rational_fitter_parsec_multi					\
	rational_function_chebychev					\
	rational_function_chebychev_opt					\
	rational_function_legendre					\
	rational_function_cosine					\
	nonlinear_fitter_eigen                 				\
	nonlinear_fitter_ceres						\
	nonlinear_fitter_ipopt						\
	nonlinear_fitter_nlopt						\
	nonlinear_fresnel_schlick					\
	nonlinear_fresnel_normalized_schlick				\
	nonlinear_fresnel_retroschlick					\
	nonlinear_shadowing_smith					\
	nonlinear_shadowing_schlick					\
	nonlinear_function_diffuse					\
#	nonlinear_function_microfacets					\
	nonlinear_function_abc						\
	nonlinear_function_beckmann					\
	nonlinear_function_retrobeckmann				\
	nonlinear_function_blinn					\
	nonlinear_function_retroblinn					\
	nonlinear_function_retroyoo					\
	nonlinear_function_ward 					\
	nonlinear_function_spherical_gaussian  				\
	nonlinear_function_lafortune					\
	nonlinear_function_isotropic_lafortune				\
	data_merl							\
	data_brdf_slice							\
	data_interpolant						\
#	data_interpolant_matlab						\
#	data_astm

