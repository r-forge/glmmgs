#ifndef GLMMGS_RANDOMEFFECTS_COVARIANCEMODEL_IDENTITYMODEL_H
#define GLMMGS_RANDOMEFFECTS_COVARIANCEMODEL_IDENTITYMODEL_H

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
				// IdentityModel
				class IdentityModel : public ICovarianceModel
				{
				private:
					// Fields
					const int size;

					// Implementation
					void Decompose(const ImmutableTriangularMatrix<double> & precision);
					int UpdateComponentsImpl(const ImmutableVector<double> & beta, const Control & control);
					Vector<double> CoefficientsUpdate(const ImmutableVector<double> & jacobian, const ImmutableVector<double> & beta) const;

				public:
					// Construction
					IdentityModel(int nvars, const ImmutableVector<double> & theta);
					~IdentityModel();
				};
			}
		}
	}
}

#endif
