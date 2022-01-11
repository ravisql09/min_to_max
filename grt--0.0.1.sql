drop aggregate if exists min_to_max(int);
drop function if exists grt_finalfunc(point);
drop function if exists grt_sfunc(point,point);

create function
  grt_sfunc( point,int)
returns
  point
as
  'grt.so', 'grt_sfunc'
language c
immutable;

create function grt_finalfunc(agg_state point)
returns record
immutable
language plpgsql
as $$
DECLARE 
ret record;
begin
  select agg_state[0],agg_state[1] into ret;
  return ret;
end;
$$;

create aggregate min_to_max(int)
(
    sfunc = grt_sfunc,
    stype = point,
    finalfunc = grt_finalfunc
);
