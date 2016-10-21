/*
 * TestContour.cpp
 *
 *  Created on: Oct 17, 2016
 *      Author: nandi
 */

#include "TestContour.h"

TestContour::TestContour(int argc, const char**argv ) {
	int i,j;
	PLFLT *xg1=new PLFLT[XPTS];
	PLFLT *yg1=new PLFLT[YPTS];
	PLcGrid cgrid1;PLcGrid2 cgrid2;
	PLFLT **z,**w;
	PLFLT xx,yy,argx,argy,distort;
	static PLINT mark=1500;
	static PLINT space=1500;
	pls=new plstream();

	//Parse and process command line arguments
	pls->parseopts(&argc,argv,PL_PARSE_FULL);
	//Initialize plplot
	pls->scolbg(255,255,255);
	pls->sdev("tk");
	pls->init();
	PLFLT x1=1.0,y1=1.0,x2=5.0,y2=5.0;
	pls->scol0(0,0,0,0);

//	pls->init();
//	pls->Alloc2dGrid(&z,XPTS,YPTS);
//	pls->Alloc2dGrid(&w,XPTS,YPTS);
//
//	for(i=0;i<XPTS;i++){
//		xx=(PLFLT)(i-(XPTS/2))/(PLFLT)(XPTS/2);
//		for (j=0;j<YPTS;j++){
//			yy=(PLFLT)(j-(YPTS/2))/(PLFLT)(YPTS/2)-1.0;
//			z[i][j]=xx*xx-yy*yy;
//			w[i][j]=2*xx*yy;
//		}
//	}
//	cgrid1.xg=xg1;
//	cgrid1.yg=yg1;
//	cgrid1.nx=XPTS;
//	cgrid1.ny=YPTS;
//	pls->Alloc2dGrid(&cgrid2.xg,XPTS,YPTS);
//	pls->Alloc2dGrid(&cgrid2.yg,XPTS,YPTS);
//	cgrid2.nx=XPTS;
//	cgrid2.ny=YPTS;
//
//	for ( i = 0; i < XPTS; i++ )
//	{
//		for ( j = 0; j < YPTS; j++ )
//		{
//			mypltr( (PLFLT) i, (PLFLT) j, &xx, &yy, NULL );
//
//			argx    = xx * 3.14 / 2;
//			argy    = yy * 3.14 / 2;
//			distort = 0.4;
//
//			cgrid1.xg[i] = xx + distort * cos( argx );
//			cgrid1.yg[j] = yy - distort * cos( argy );
//
//			cgrid2.xg[i][j] = xx + distort * cos( argx ) * cos( argy );
//			cgrid2.yg[i][j] = yy - distort * cos( argx ) * cos( argy );
//		}
//	}
//	pls->setcontlabelformat( 4, 3 );
//	pls->setcontlabelparam( 0.006, 0.3, 0.1, 1 );
//	pls->env( -1.0, 1.0, -1.0, 1.0, 0, 0 );
//	pls->col0( 2 );
//	pls->cont( z, XPTS, YPTS, 1, XPTS, 1, YPTS, clevel, 11, mypltr, NULL );
//	pls->styl( 1, &mark, &space );
//	pls->col0( 3 );
//	pls->cont( w, XPTS, YPTS, 1, XPTS, 1, YPTS, clevel, 11, mypltr, NULL );
//	pls->styl( 0, &mark, &space );
//	pls->col0( 1 );
//	pls->lab( "X Coordinate", "Y Coordinate", "Streamlines of flow" );
//	pls->setcontlabelparam( 0.006, 0.3, 0.1, 0 );
//
//	pls->setcontlabelparam(0.006, 0.3, 0.1, 1);
//	pls->env(-1.0, 1.0, -1.0, 1.0, 0, 0);
//	pls->col0(2);
//	pls->cont(z, XPTS, YPTS, 1, XPTS, 1, YPTS, clevel, 11,
//		pltr1, (void *) &cgrid1 );
//	pls->styl(2, &mark, &space);
//	pls->col0(3);
//	pls->cont(w, XPTS, YPTS, 1, XPTS, 1, YPTS, clevel, 11,
//		pltr1, (void *) &cgrid1 );
//	pls->styl(0, &mark, &space);
//	pls->col0(1);
//	pls->lab("X Coordinate", "Y Coordinate", "Streamlines of flow");
//	pls->setcontlabelparam(0.006, 0.3, 0.1, 0);
//
//
	pls->setcontlabelparam( 0.006, 0.3, 0.1, 1);
	polar();

}

TestContour::~TestContour() {
	// TODO Auto-generated destructor stub
}


void TestContour::polar()
// polar contour plot example.
{
    int      i, j;
    PLFLT    *px = new PLFLT[PERIMETERPTS];
    PLFLT    *py = new PLFLT[PERIMETERPTS];
    PLcGrid2 cgrid2;
    PLFLT    **z;
    PLFLT    t, r, theta;
    PLFLT    *lev = new PLFLT[10];

    pls->Alloc2dGrid( &cgrid2.xg, RPTS, THETAPTS );
    pls->Alloc2dGrid( &cgrid2.yg, RPTS, THETAPTS );
    pls->Alloc2dGrid( &z, RPTS, THETAPTS );
    cgrid2.nx = RPTS;
    cgrid2.ny = THETAPTS;

    pls->env( -1., 1., -1., 1., 0, -2 );
    pls->col0( 1 );

    // Perimeter
    for ( i = 0; i < PERIMETERPTS; i++ )
    {
        t     = ( 2. * M_PI / ( PERIMETERPTS - 1 ) ) * (PLFLT) i;
        px[i] = cos( t );
        py[i] = sin( t );
    }
    pls->line( PERIMETERPTS, px, py );

    // Create data to be contoured.

    for ( i = 0; i < RPTS; i++ )
    {
        r = i / (PLFLT) ( RPTS - 1 );
        for ( j = 0; j < THETAPTS; j++ )
        {
            theta           = ( 2. * M_PI / (PLFLT) ( THETAPTS - 1 ) ) * (PLFLT) j;
            cgrid2.xg[i][j] = r * cos( theta );
            cgrid2.yg[i][j] = r * sin( theta );
            z[i][j]         = r;
        }
    }

    for ( i = 0; i < 10; i++ )
    {
        lev[i] = 0.05 + 0.10 * (PLFLT) i;
    }

    pls->col0( 2 );
    pls->cont( z, RPTS, THETAPTS, 1, RPTS, 1, THETAPTS, lev, 10,pltr2, (void *) &cgrid2 );
    pls->col0( 1 );
    pls->lab( "", "", "Polar Contour Plot" );

    pls->Free2dGrid( cgrid2.xg, RPTS, THETAPTS );
    pls->Free2dGrid( cgrid2.yg, RPTS, THETAPTS );
    pls->Free2dGrid( z, RPTS, THETAPTS );

    delete[] px;
    delete[] py;
    delete[] lev;
}

