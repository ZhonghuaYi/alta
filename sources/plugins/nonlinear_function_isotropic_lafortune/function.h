#pragma once

// Include STL
#include <vector>
#include <string>

// Interface
#include <core/function.h>
#include <core/rational_function.h>
#include <core/data.h>
#include <core/fitter.h>
#include <core/args.h>
#include <core/common.h>

/*! \brief A isotropic_lafortune lobe class. It is provided for testing with the nonlinear
 *  fitting algorithms.
 *
 *  \details
 *  A isotropic_lafortune lobe is defined as \f$k_d + (L^T M V)^n\f$. We fit the restricted
 *  version where the M matrix is diagonal of coefficients \f$(Cx, Cy, Cz)\f$
 *  \todo Fitting the diffuse part is not stable
 */
class isotropic_lafortune_function : public nonlinear_function
{

	public: // methods

		isotropic_lafortune_function() : _n(1) { }

		// Overload the function operator
		virtual vec operator()(const vec& x) const ;
		virtual vec value(const vec& x) const ;
		virtual vec value(const vec& x, const vec& p) const;

		//! \brief Load function specific files
		virtual void load(const std::string& filename) ;

		//! \brief Boostrap the function by defining the diffuse term
		virtual void bootstrap(const data* d, const arguments& args);

		//! \brief Number of parameters to this non-linear function
		virtual int nbParameters() const ;

		//! \brief Get the vector of parameters for the function
		virtual vec parameters() const ;

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

		//! \brief Provide the parametrization of the input space of the function.
		//! For this one, we fix that the parametrization is in THETAD_PHID
		virtual params::input parametrization() const
		{
			return params::CARTESIAN ;
		}
		virtual void setParametrization(params::input new_param)
		{
			std::cerr << "<<ERROR>> Cannot change the ouput parametrization " << __FILE__ << ":" << __LINE__ << std::endl;
			throw;
		}

		//! \brief Set the number of output dimensions
		void setDimY(int nY);

		//! \brief Set the number of lobes to be used in the fit
		void setNbLobes(int N);

	protected: // methods

		virtual void save(const std::string& filename) const;


		//! \brief Output the function using a BRDF Explorer formating.
		virtual void save_brdfexplorer(const std::string& filename,
		                               const arguments& args) const;

	private: // methods

		//! \brief Provide the coefficient of the monochromatic lobe number
		//! n for the color channel number c.
		void getCurrentLobe(int n, int c, double& Cx, double& Cz, double& N) const 
		{
			Cx = _C[(n*_nY + c)*2 + 0];
			Cz = _C[(n*_nY + c)*2 + 1];
			N  = _N[n*_nY + c];
		}


	private: // data

		//! \brief The isotropic_lafortune lobe data
		int _n; // Number of lobes
		vec _N, _C; // Lobes data
		vec _kd; // Diffuse term
} ;

