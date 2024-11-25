cmake_minimum_required(VERSION 3.16)
project(VulkanMap)

set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)

add_subdirectory(lib/glfw-3.3.2)
SET(GLM_TEST_ENABLE OFF CACHE BOOL "GLM Build unit tests")
add_subdirectory(lib/glm-0.9.9.6      EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan GLM::GLM)


function long2tile(lon,zoom) {
		return (Math.floor((lon+180)/360*Math.pow(2,zoom)));
	}

	function lat2tile(lat,zoom)  {
		return (Math.floor((1-Math.log(Math.tan(lat*Math.PI/180) + 1/Math.cos(lat*Math.PI/180))/Math.PI)/2 *Math.pow(2,zoom)));
	}
	
		function tile2long(x,z) {
		return (x/Math.pow(2,z)*360-180);
	}

	function tile2lat(y,z) {
		var n=Math.PI-2*Math.PI*y/Math.pow(2,z);
		return (180/Math.PI*Math.atan(0.5*(Math.exp(n)-Math.exp(-n))));
	}


	function getTileRect(x, y, zoom) {

		var c1 = new mapboxgl.LngLat(tile2long(x, zoom), tile2lat(y, zoom));
		var c2 = new mapboxgl.LngLat(tile2long(x + 1, zoom), tile2lat(y + 1, zoom));

		return new mapboxgl.LngLatBounds(c1, c2);
	}
	
		function getGrid(zoomLevel) {

		var bounds = getBounds();

		var rects = [];

		var outputScale = $("#output-scale").val();
		//var thisZoom = zoomLevel - (outputScale-1)
		var thisZoom = zoomLevel

		var TY    = lat2tile(bounds.getNorthEast().lat, thisZoom);
		var LX   = long2tile(bounds.getSouthWest().lng, thisZoom);
		var BY = lat2tile(bounds.getSouthWest().lat, thisZoom);
		var RX  = long2tile(bounds.getNorthEast().lng, thisZoom);

		for(var y = TY; y <= BY; y++) {
			for(var x = LX; x <= RX; x++) {

				var rect = getTileRect(x, y, thisZoom);

				if(isTileInSelection(rect)) {
					rects.push({
						x: x,
						y: y,
						z: thisZoom,
						rect: rect,
					});
				}

			}
		}

		return rects
	}

	function getAllGridTiles() {
		var allTiles = [];

		for(var z = getMinZoom(); z <= getMaxZoom(); z++) {
			var grid = getGrid(z);
			// TODO shuffle grid via a heuristic (hamlet curve? :/)
			allTiles = allTiles.concat(grid);
		}

		return allTiles;
	}