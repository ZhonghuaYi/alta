#pragma once

// Include STL
#include <vector>
#include <string>

// Interface
#include <core/function.h>
#include <core/data.h>
#include <core/fitter.h>
#include <core/args.h>
#include <core/common.h>

/*! \brief A spherical Gaussian lobe class.
 *
 *  \details
 *  A spherical_gaussian lobe is defined as \f$k_s exp(n (v.p - 
 *  1))\f$. Where \f$n\f$ is the roughness control and \f$p\f$
 *  is the lobe direction and \f$v\f$ the evaluation direction.
 *
 *
 *  <h3>Plugin parameters</h3>
 *
 *  <ul>
 *     <li><b>bootstrap</b> function will read the arguments to set 
 *     lobe and evaluation directions.</li>
 *  </ul>
 */
class spherical_gaussian_function : public nonlinear_function
{

	public: // methods

		spherical_gaussian_function() : _n(1) 
		{ 
			setParametrization(params::CARTESIAN);
			setDimX(6);
		}

		// Overload the function operator
		virtual vec operator()(const vec& x) const ;
		virtual vec value(const vec& x) const ;

		//! \brief Load function specific files
		virtual void load(std::istream& in) ;

		//! \brief Export function
		virtual void save_call(std::ostream& out, const arguments& args) const;
      virtual void save_body(std::ostream& out, const arguments& args) const;

		//! \brief Boostrap the function by defining the diffuse term
		//!
		//! \details
		virtual void bootstrap(const data* d, const arguments& args);

		//! \brief Number of parameters to this non-linear function
		virtual int nbParameters() const ;

		//! \brief Get the vector of parameters for the function
		virtual vec parameters() const ;

		//! \brief get the min values for the parameters
		virtual vec getParametersMin() const;

		//! \brief Update the vector of parameters for the function
		virtual void setParameters(const vec& p) ;

		//! \brief Obtain the derivatives of the function with respect to the
		//! parameters. 
		virtual vec parametersJacobian(const vec& x) const ;

		//! \brief Provide the dimension of the input space of the function
		virtual int dimX() const
		{
			return 6;
		}
		
		//! \brief Set the number of output dimensions
		void setDimY(int nY);

		//! \brief Set the number of lobes to be used in the fit
		void setNbLobes(int N);

	private: // methods


	private: // data

		vec _n, _ks; // Lobes data
} ;

