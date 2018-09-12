open Koa;
open KoaRoute.Route;

let app = App.make ();
let route = route;

let middleware = (_, next) => {
  next();
};

let opts: options = [||];

App.use(app, middleware);
App.use(app,
  get(route, "/:haloumi", (ctx, param, _) => {
    let Param(param) = param;
    ctx##body #= param;
  }, ~opts=opts)
);

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
