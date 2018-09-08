open Koa;

module Http = {
  type http;
  [@bs.module "http"] external create : App.t('a) => http = "Server";
  [@bs.send] external listen : (http, int, unit => unit) => unit = "";
};