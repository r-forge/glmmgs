#ifndef GLMMGS_RANDOMEFFECTS_COVARIANCEMODEL_ICOVARIANCEMODEL_H
#define GLMMGS_RANDOMEFFECTS_COVARIANCEMODEL_ICOVARIANCEMODEL_H

#include "../../../Standard.h"
#include "../../../Controls.h"

namespace GlmmGS
{
	namespace RandomEffects
	{
		namespace Global
		{
			namespace CovarianceModels
			{
				// CovarianceModel
				class ICovarianceModel
				{
				protected:
					// Fields
					Vector<double> theta;
					const bool constant;
					CholeskyDecomposition chol;
					CholeskyDecomposition beta_precision_chol;

					// Implementation
					int Update(const TriangularMatrix<double> & minus_hessian,
							const Vector<double> & jacobian, const Controls & controls);
				public:
					// Construction
					ICovarianceModel(int npars, Matrix<const double> S);
					virtual ~ICovarianceModel();

					// Properties
					const Vector<double> & Components() const;
					TriangularMatrix<double> Covariance() const;
					TriangularMatrix<double> CoefficientCovariance() const;

					// Methods
					virtual void Decompose(const TriangularMatrix<double> & precision) = 0;
					virtual int Update(const Vector<double> & beta, const Controls & controls) = 0;
					virtual Vector<double> UpdateCoefficients(const Vector<double> & jacobian, const Vector<double> & beta) const = 0;
				};
			}
		}
	}
}

#endif
