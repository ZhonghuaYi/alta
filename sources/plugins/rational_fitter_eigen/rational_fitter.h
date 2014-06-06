#pragma once

// Include STL
#include <vector>
#include <string>

// Interface
#include <core/function.h>
#include <core/data.h>
#include <core/fitter.h>
#include <core/args.h>
#include <core/rational_function.h>
#include <core/vertical_segment.h>

/*! \brief A least square fitter for rational function using the library Eigen
 *  \ingroup plugins
 */
class rational_fitter_eigen : public fitter
{

	public: // methods

		rational_fitter_eigen() ;
		virtual ~rational_fitter_eigen() ;

		// Fitting a data object
		//
		virtual bool fit_data(const ptr<data> d, function* fit, const arguments& args) ;

		// Provide user parameters to the fitter
		//
		virtual void set_parameters(const arguments& args) ;

	protected: // function

		// Fitting a data object using np elements in the numerator and nq 
		// elements in the denominator
		virtual bool fit_data(const ptr<vertical_segment> d, int np, int nq, rational_function* fit) ;
		virtual bool fit_data(const ptr<vertical_segment> dat, int np, int nq, int ny, rational_function_1d* fit) ;

	protected: // data

		// min and Max usable np and nq values for the fitting
		int _np, _nq ;
} ;

