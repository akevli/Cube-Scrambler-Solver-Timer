// Copyright (c) 2020 [Your Name]. All rights reserved.
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <search.h>

#include "my_app.h"

using cinder::app::App;
using cinder::app::RendererGl;

namespace myapp {

const int kSamples = 8;
const int kWidth = 1000;
const int kHeight = 1000;

void SetUp(App::Settings* settings) {
  // Randomize seed once program starts
  srand( time( NULL ) );
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("3x3 Timer/Solver");
}

}  // namespace myapp

// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)