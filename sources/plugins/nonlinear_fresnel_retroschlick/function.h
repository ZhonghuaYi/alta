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


class retro_schlick : public fresnel
{

	public: // methods

		//! \brief Load function specific files
		virtual void load(std::istream& in) ;

		virtual void save_call(std::ostream& out, const arguments& args) const;
		virtual void save_body(std::ostream& out, const arguments& args) const;

	protected: // methods

		virtual vec fresnelValue(const vec& x) const;
		
		//! \brief Number of parameters to this non-linear function
		virtual int nbFresnelParameters() const ;

		//! \brief Get the vector of parameters for the function
		virtual vec getFresnelParameters() const ;

		//! \brief Update the vector of parameters for the function
		virtual void setFresnelParameters(const vec& p) ;

		//! Get the vector of min parameters for the function
		virtual vec getFresnelParametersMin() const
		{
            vec m = vec::Zero(dimY());
            return m;
		}

		//! Get the vector of min parameters for the function
		virtual vec getFresnelParametersMax() const
		{
			vec M(dimY());
            for(int i=0; i<dimY(); ++i) { M[i] = 1.0; }
			return M;
		}

		//! \brief Obtain the derivatives of the function with respect to the
		//! parameters. 
		virtual vec getFresnelParametersJacobian(const vec& x) const ;

		//! \brief Boostrap the function by defining the diffuse term
		virtual void fresnelBootstrap(const data* d, const arguments& args);


	private: // data

		//! Unidimensional Fresnel reflectance at theta = 0
        vec R;
} ;
