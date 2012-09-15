#ifndef GLMMGS_RANDOMEFFECTS_COVARIANCEMODEL_PRECISIONMODEL_H
#define GLMMGS_RANDOMEFFECTS_COVARIANCEMODEL_PRECISIONMODEL_H

#include "../../../Standard.h"
#include "ICovarianceModel.h"

namespace GlmmGS
{
	namespace RandomEffects
	{
		namespace Global
		{
			namespace CovarianceModels
			{
				// PrecisionModel
				class PrecisionModel : public ICovarianceModel
				{
				private:
					// Fields
					Matrix<const double> R;

					// Implementation
					void Decompose(const TriangularMatrix<double> & precision);
					int Update(const Vector<double> & beta, const Controls & controls);
					Vector<double> UpdateCoefficients(const Vector<double> & jacobian, const Vector<double> & beta) const;

				public:
					// Construction
					PrecisionModel(Matrix<const double> R);
					~PrecisionModel();

					// Properties
					TriangularMatrix<double> CoefficientCovariance() const;
				};
			}
		}
	}
}

#endif
