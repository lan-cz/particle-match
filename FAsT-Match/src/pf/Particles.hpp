//
// Created by rokas on 17.6.20.
//

#pragma once

#include <vector>
#include <memory>
#include <opencv2/core/types.hpp>
#include <FAsT-Match/MatchConfig.h>
#include "Particle.hpp"

class Particles : public std::vector<Particle> {
public:
    void init(cv::Point2i startLocation, const cv::Size mapSize, double radius, int particleCount, bool use_gaussian);
    std::vector<fast_match::MatchConfig> getConfigs();
    void propagate(const cv::Point2f& movement, float alpha = 2.f);
    void assignProbabilities(const std::vector<fast_match::MatchConfig>& configs, const std::vector<double> probabilities);


    void addParticle(Particle p);

protected:
    std::shared_ptr<std::vector<float>> s_initial = std::make_shared<std::vector<float>>();

    cv::RNG rng;

    void addParticle(int x, int y);

    bool isLocationOccupied(int x, int y);

public:
    std::vector<cv::Point> evaluate(cv::Mat image, cv::Mat templ, int no_of_points);

    void printProbabilities();

    Particle sample();

    void normalize();

    void sortAscending();

    cv::Point2i getWeightedSum() const;

    void setScale(float min, float max, uint32_t steps = 5);
};


