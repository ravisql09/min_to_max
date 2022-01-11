#include "postgres.h"
#include "fmgr.h"
#include "utils/geo_decls.h"
#include "utils/elog.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

PG_FUNCTION_INFO_V1(grt_sfunc);

Datum
grt_sfunc(PG_FUNCTION_ARGS)
{
        Point *result = (Point *) palloc(sizeof(Point));
        Point *new_agg_state = (Point *) palloc(sizeof(Point));
        double el = PG_GETARG_INT32(1);
        Point *pointx = PG_GETARG_POINT_P(0);

bool isnull = PG_ARGISNULL(0);
        if(isnull) {
                new_agg_state->x = el;
                new_agg_state->y = el;
                PG_RETURN_POINT_P(new_agg_state);
        }

        new_agg_state->x = el;


   if(new_agg_state->x < pointx->x) {
                result->x = new_agg_state->x;
        } else {
                result->x = pointx->x;
        }




   if(new_agg_state->x > pointx->y) {
                result->y = new_agg_state->x;
        } else {
                result->y = pointx->y;
        }



elog(INFO, "x is %f", result->x);
elog(INFO, "y is %f", result->y);


PG_RETURN_POINT_P(result);
}
