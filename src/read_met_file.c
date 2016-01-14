#include "read_met_file.h"

void read_daily_met_data(char **argv, control *c, met *m)
{
    FILE  *fp;
    char   line[STRING_LENGTH];
    int    file_len = 0;
    int    i = 0;
    int    nvars = 23;
    int    skipped_lines = 0;
    double current_yr;

    if ((fp = fopen(c->met_fname, "r")) == NULL) {
		fprintf(stderr, "Error: couldn't open Met file %s for read\n",
                c->met_fname);
		exit(EXIT_FAILURE);
	 }

    /* work out how big the file is */
    while (fgets(line, STRING_LENGTH, fp) != NULL) {
        /* ignore comment line */
        if (*line == '#')
            continue;
        file_len++;
    }
    rewind(fp);
    c->num_days = file_len;

    /* allocate memory for meteorological arrays */
    if ((m->year = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for year array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->prjday = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for prjday array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->sw_rad = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for sw_rad array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tair = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tair array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->rain = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for rain array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tsoil = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tsoil array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tam = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tam array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tpm = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tpm array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tmin = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tmin array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tmax = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tmax array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tday = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tday array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->vpd_am = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for vpd_am array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->vpd_pm = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for vpd_pm array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->vpd_avg = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for vpd_avg array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->co2 = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for co2 array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->ndep = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for ndep array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->wind = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for wind array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->press = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for press array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->par = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for par array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->wind_am = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for wind_am array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->wind_pm = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for wind_pm array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->sw_rad_am = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for sw_rad_am array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->sw_rad_pm = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for sw_rad_pm array\n");
		exit(EXIT_FAILURE);
    }

    current_yr = m->year[0];

    i = 0;
    c->num_years = 0;
    skipped_lines = 0;
    while (fgets(line, STRING_LENGTH, fp) != NULL) {
        /* ignore comment line */
        if (*line == '#') {
            skipped_lines++;
            continue;
        }

        if (sscanf(line, "%lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf", \
                          &(m->year[i]), &(m->prjday[i]), &(m->sw_rad[i]), \
                          &(m->tair[i]), &(m->rain[i]), &(m->tsoil[i]), \
                          &(m->tam[i]), &(m->tpm[i]), &(m->tmin[i]), \
                          &(m->tmax[i]), &(m->tday[i]), &(m->vpd_am[i]), \
                          &(m->vpd_pm[i]), &(m->vpd_avg[i]), &(m->co2[i]), \
                          &(m->ndep[i]), &(m->wind[i]), &(m->press[i]), \
                          &(m->par[i]), &(m->wind_am[i]), &(m->wind_pm[i]), \
                          &(m->sw_rad_am[i]), &(m->sw_rad_pm[i])) != nvars) {
            fprintf(stderr, "%s: badly formatted input in met file on line %d %d\n", \
                    *argv, (int)i+1+skipped_lines, nvars);
            exit(EXIT_FAILURE);
        }

        /* Build an array of the unique years as we loop over the input file */
        if (current_yr != m->year[i]) {
            c->num_years++;
            current_yr = m->year[i];
        }
        i++;
    }
    fclose(fp);
    return;
}

void read_subdaily_met_data(char **argv, control *c, met *m)
{
    FILE  *fp;
    char   line[STRING_LENGTH];
    int    file_len = 0;
    int    i = 0;
    int    nvars = 12;
    int    skipped_lines = 0;
    double current_yr, temp_HOD;


    if ((fp = fopen(c->met_fname, "r")) == NULL) {
		fprintf(stderr, "Error: couldn't open Met file %s for read\n",
                c->met_fname);
		exit(EXIT_FAILURE);
	 }

    /* work out how big the file is */
    while (fgets(line, STRING_LENGTH, fp) != NULL) {
        /* ignore comment line */
        if (*line == '#')
            continue;
        file_len++;
    }
    rewind(fp);
    c->num_days = file_len;

    /* allocate memory for meteorological arrays */
    if ((m->year = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for year array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->doy = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for doy array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->rain = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for rain array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->par = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for par array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tair = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tair array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->tsoil = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for tsoil array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->vpd = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for vpd array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->co2 = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for co2 array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->ndep = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for ndep array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->wind = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for wind array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->press = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for press array\n");
		exit(EXIT_FAILURE);
    }

    if ((m->diffuse_frac = (double *)calloc(c->num_days, sizeof(double))) == NULL) {
        fprintf(stderr,"Error allocating space for diffuse_frac array\n");
		exit(EXIT_FAILURE);
    }


    current_yr = m->year[0];

    i = 0;
    c->num_years = 0;
    skipped_lines = 0;

    while (fgets(line, STRING_LENGTH, fp) != NULL) {
        /* ignore comment line */
        if (*line == '#') {
            skipped_lines++;
            continue;
        }



        if (sscanf(line, "%lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf,\
                          %lf,%lf,%lf", \
                          &(m->year[i]), &(m->doy[i]), &temp_HOD, \
                          &(m->rain[i]), &(m->par[i]), &(m->tair[i]), \
                          &(m->tsoil[i]), &(m->vpd[i]), &(m->co2[i]), \
                          &(m->ndep[i]), &(m->wind[i]), \
                          &(m->press[i])) != nvars) {
            fprintf(stderr, "%s: badly formatted input in met file on line %d %d\n", \
                    *argv, (int)i+1+skipped_lines, nvars);
            exit(EXIT_FAILURE);
        }

        /* calculates diffuse frac from half-hourly incident radiation */
        m->diffuse_frac[i] = get_diffuse_frac(m->doy[i], m->par[i]);


        /* Build an array of the unique years as we loop over the input file */
        if (current_yr != m->year[i]) {
            c->num_years++;
            current_yr = m->year[i];
        }
        i++;
    }
    fclose(fp);
    return;
}

double get_diffuse_frac(int doy, double par) {
    /*
        For the moment, I am only going to implement Spitters, so this is a bit
        of a useless wrapper function.

    */

    return spitters(doy, par);
}

double spitters(int doy, double par) {

    /*

    Spitters algorithm to estimate the diffuse component from the measured
    irradiance.

    Parameters:
    ----------
    doy : int
        day of year
    zenith : double
        sun zenith angle [degrees]
    par : double
        total par measured [umol m-2 s-1]

    Returns:
    -------
    diffuse : double
        diffuse component of incoming radiation

    References:
    ----------
    * Spitters, C. J. T., Toussaint, H. A. J. M. and Goudriaan, J. (1986)
      Separating the diffuse and direct component of global radiation and its
      implications for modeling canopy photosynthesis. Part I. Components of
      incoming radiation. Agricultural Forest Meteorol., 38:217-229.
    */

    double sw_rad;
    double diffuse;

    printf("%lf\n", PAR_2_SW);
    exit(EXIT_SUCCESS);

    return (diffuse);

}
