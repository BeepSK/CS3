#ifndef GAUSS_QUADS_H
#define GAUSS_QUADS_H

/* Load Gauss-Legendre nodes (positive roots) and weights for given n.
   Supported n: 4,6,8,10,12 (positive half only: n/2 values). */
void gauss_legendre(int n, double x[], double w[]);

/* Load Gauss-Hermite nodes (positive roots) and weights for given n.
   Supported n: 4,6,8,10,12 (positive half only). */
void gauss_hermite(int n, double x[], double w[]);

/* Load Gauss-Laguerre nodes (positive roots) and weights for given n.
   Supported n: 4,6,8,10 (full positive roots). */
void gauss_laguerre(int n, double x[], double w[]);

#endif /* GAUSS_QUADS_H */

