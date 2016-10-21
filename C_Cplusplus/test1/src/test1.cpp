// example of a simple program using the PLPlot library to plot results.
//  by Jim Crumley  20090120
//  updated 20110125 for latest version of PLPlot
//  updates 20120122 for latest version of PLPlot
//  updated 20130123 for compile line for newest version of Fedora


// old line - ignore: g++ plplot_example.C -o plplot_example `pkg-config --cflags --libs plplotd-c++`
// compile with:
//   g++ plplot_example.C -o plplot_example -I/usr/include/plplot  -lplplotcxxd  -lplplotd
using namespace std;

// Includes for plplot
#include <plplot/plstream.h>
#include <plplot/plplot.h>
#include <iostream>

int main (int argc, const char ** argv)
{
  PLFLT xmin =0, ymin=0, xmax=5, ymax=30,
    x[6]= {0.0, 1.0, 2.0, 3.0, 4.0, 5.0},
    y[6] = {0., 1.0, 4.0, 9.1, 15.5, 25.3};
  PLINT just=0, axis=0;
  plstream *pls;
  plinit();


  // plplot initialization

  pls = new plstream();  // declare plplot object

  plsdev("xwin"); // sets the plot device to WX Widget which
                 // allows for viewing and saving the plot to a file
                 // Note that saving postscript from within widgets is buggy.
                 // other useful values in place of wxwidgets:
                 // xwin - X-window display to screen
                 // ps - postscript file
                 // pscairo - color postscript file
                 // pdfcairo - color pdf file
                 // Or just comment out line to get a list of choices
  //plsdev("ps");
  //plsdev("pscairo"); //cairo uses the same color scheme as on screen - black on
                        //red on black default
//  plsfnam("test2.ps");// sets the names of the output file

  // Parse and process command line arguments.
  //pls->parseopts( &argc, argv, PL_PARSE_FULL ); // device and other options
                // can be set from the command-line:
                // -dev devname        sets the output device to "devname"
                // -o output_file      sets the output file name to output_file                // -h                  gives a list of all possible options


  pls->init();           // start plplot object
  pls->env(xmin, xmax, ymin, ymax, just, axis );
    //Setup window size
    // - just=0 sets axis so they scale indepedently
    // - axis=0 draw axis box, ticks, and numeric labels
    //   see "man plenv" for details
  pls->lab( "(x)", "(y)", "PlPlot example title");

  // Plot the data points - (num_points, x, y. plot_symbol)
  //  - plot_symbol=9 sets a circle with a dot in the
  // middle for the plot symbol - see "man plpoin"
  //pls->poin( 6, x, y, 9 );
  //pls->sym( 6, x, y, 9 );
  pls->line( 6, x, y);
  delete pls; // close plot

  return 0;
}
