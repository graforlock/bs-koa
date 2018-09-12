open Koa;
open KoaRoute;

let app = App.make ();
let route = route;

let middleware = (_, next) => {
  next();
};

let opts: Route.options = [||];

App.use(app, middleware);
App.use(app,
  get(route, "/:haloumi", (ctx, param, next) => {
    switch((param, next)) {
    | (Param(param), Next(n)) => ctx##body #= param; next()
    | _ => ignore
    };
  }, ~opts=opts)
);

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
