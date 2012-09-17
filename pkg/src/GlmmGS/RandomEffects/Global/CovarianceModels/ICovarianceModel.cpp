#include "ICovarianceModel.h"
#include "../../../Controls.h"

namespace GlmmGS
{
	namespace RandomEffects
	{
		namespace Global
		{
			namespace CovarianceModels
			{
				// Construction
				ICovarianceModel::ICovarianceModel(int npars, Matrix<const double> S)
					: theta(npars), constant(S.NumberOfRows() > 0)
				{
				}

				ICovarianceModel::~ICovarianceModel()
				{
				}

				// Properties
				const Vector<double> & ICovarianceModel::Components() const
				{
					return this->theta;
				}

				TriangularMatrix<double> ICovarianceModel::Covariance() const
				{
					return this->constant ? TriangularMatrix<double>(this->theta.Size()) : this->chol.Inverse();
				}

				TriangularMatrix<double> ICovarianceModel::CoefficientCovariance() const
				{
					return this->beta_precision_chol.Inverse();
				}

				// Implementation
				int ICovarianceModel::Update(const TriangularMatrix<double> & minus_hessian,
						const Vector<double> & jacobian, const Controls & controls)
				{
					if (!this->constant)
					{
						// Calculate update
						try
						{
							this->chol.Decompose(minus_hessian);
							Vector<double> h = chol.Solve(jacobian);
							const int update = controls.Comparer().IsZero(h, this->theta) ? 0 : 1;
							if (controls.Verbose())
								Print("Max update covariance components: %g\n", MaxAbs(h));
							this->theta += h;
							return update;
						}
						catch(Exceptions::Exception &)
						{
							//throw Exceptions::Exception("Failed to update covariance components");
							Print("Warning: Failed to update covariance components\n");
							return 1;
						}
					}

					return 0;
				}
			}
		}
	}
}
