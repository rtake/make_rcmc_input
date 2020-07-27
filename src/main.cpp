# include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
  char line[256];

  vector<string> inptmp;

  vector<string> siml_temperature = {"500","5000","50000"};
  vector<string> timescale = {"1","1e+1","1e+2","1e+3","1e+4","1e+5","1e+6","1e+7","1e+8","1e+9","1e+10","1e+11","1e+12","1e+13","1e+14","1e+15","1e+16","1e-1","1e-2","1e-3","1e-4","1e-5","1e-6","1e-7","1e-8","1e-9","1e-10","1e-11","1e-12","1e-13","1e-14","1e-15","1e-16"};
  string com(argv[1]), rcmc("rcmcinp"), simliniteqs;
  FILE *fpout=stdout, *fpin;

  com += ".com"; // cout << com;
  fpin = fopen(com.c_str(),"r");

  inptmp.push_back("%infile="+string(argv[1])+"\n"); // fprintf(fpout,"%%infile=%s\n", argv[1]);
  inptmp.push_back("# REPATH/PM6\n"); // fprintf(fpout,"# REPATH/PM6\n");
  inptmp.push_back("RCMC input for "+string(argv[1])+"\n"); // fprintf(fpout,"RCMC input for %s\n", argv[1]);

  while( fgets(line,256,fpin) ) {
    if( strstr(line,"%infile") ) { continue; }
    if( strstr(line,"#") ) { continue; }
    if( string(line) == "\n") { continue; }

    inptmp.push_back(line); // fprintf(fpout,"%s",line);
    if( strstr(line,"Options") ) { break; }
  }

  // inptmp.push_back("Options\n"); // fprintf(fpout,"Options\n");

  while( fgets(line,256,fpin) ) {
    string s(line);
    for(int i=0;i<(int)s.size();i++) { s[i] = (char)toupper(s[i]); }

    if( strstr(s.c_str(),"SIML_INITEQS") ) {
      inptmp.push_back(line); // simliniteqs = s;
    }
  }

  fclose(fpin);

  fpin = fopen(rcmc.c_str(),"r");
  while( fgets(line,256,fpin) ) {
    inptmp.push_back(line); // fprintf(fpout,"%s",line);
  }

  for(int i=0;i<(int)siml_temperature.size();i++) {
    for(int j=0;j<(int)timescale.size();j++) {
      string filename = string(argv[1])+"_rcmc_"+siml_temperature[i]+"k_"+timescale[j]+"s";
      cout << filename << endl;

      fpout = fopen((filename+".com").c_str(),"w");
      for(int k=0;k<(int)inptmp.size();k++) {
        fprintf(fpout,"%s",inptmp[k].c_str());
      }
      fprintf(fpout,"SIML_Temperature=%s\n",siml_temperature[i].c_str());
      fprintf(fpout,"Timescale=%s\n",timescale[j].c_str());
      fclose(fpout);
    }
  }

  return 0;
}
