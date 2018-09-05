open Koa;
open Route;

let app = App.make ();
let route = Route.route;

let middleware = (_, next) => {
  next();
};

let opts: Route.options = [||];

App.use(app, middleware);
App.use(app,
  Route.get(route, "/:haloumi", (ctx, param) => {
    ctx##body #= param;
  }, ~opts=opts)
);

App.listen(app, ~port=3000, ~callback=_ => Js.log({j|Listening on port 3000|j}));
